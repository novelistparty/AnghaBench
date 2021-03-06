#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u_int ;
typedef  int u_char ;
typedef  int /*<<< orphan*/  sockaddr_u ;
typedef  int /*<<< orphan*/  keystr ;
typedef  int keyid_t ;
struct TYPE_4__ {int keyid; int keytype; size_t seclen; struct TYPE_4__* next; int /*<<< orphan*/ * keyacclist; int /*<<< orphan*/  secbuf; } ;
typedef  TYPE_1__ KeyDataT ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  AF_UNSPEC ; 
 int /*<<< orphan*/ * EVP_get_digestbynid (int) ; 
 int /*<<< orphan*/  INIT_SSL () ; 
 int /*<<< orphan*/  INSIST (int) ; 
 scalar_t__ IS_IPV4 (int /*<<< orphan*/ *) ; 
 scalar_t__ IS_IPV6 (int /*<<< orphan*/ *) ; 
 int KEY_TYPE_MD5 ; 
 int /*<<< orphan*/  LOG_ERR ; 
 int /*<<< orphan*/  MD5auth_setkey (int,int,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ *) ; 
 int NID_cmac ; 
 int NTP_MAXKEY ; 
 unsigned int UINT_MAX ; 
 int atoi (char*) ; 
 int /*<<< orphan*/  auth_delkeys () ; 
 TYPE_1__* emalloc (int) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 char* fgets (char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 int /*<<< orphan*/  free_keydata (TYPE_1__*) ; 
 scalar_t__ is_ip_address (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  isdigit (unsigned char) ; 
 int /*<<< orphan*/ * keyacc_new_push (int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned int) ; 
 int keytype_from_text (char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  log_maybe (scalar_t__*,char*,...) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,...) ; 
 size_t min (size_t,int) ; 
 int /*<<< orphan*/  msyslog (int /*<<< orphan*/ ,char*,char const*,...) ; 
 scalar_t__ nerr_maxlimit ; 
 char* nexttok (char**) ; 
 char* strchr (char const*,int) ; 
 size_t strlen (char*) ; 
 int tolower (unsigned char) ; 

int
authreadkeys(
	const char *file
	)
{
	FILE	*fp;
	char	*line;
	char	*token;
	keyid_t	keyno;
	int	keytype;
	char	buf[512];		/* lots of room for line */
	u_char	keystr[32];		/* Bug 2537 */
	size_t	len;
	size_t	j;
	u_int   nerr;
	KeyDataT *list = NULL;
	KeyDataT *next = NULL;

	/*
	 * Open file.  Complain and return if it can't be opened.
	 */
	fp = fopen(file, "r");
	if (fp == NULL) {
		msyslog(LOG_ERR, "authreadkeys: file '%s': %m",
		    file);
		goto onerror;
	}
	INIT_SSL();

	/*
	 * Now read lines from the file, looking for key entries. Put
	 * the data into temporary store for later propagation to avoid
	 * two-pass processing.
	 */
	nerr = 0;
	while ((line = fgets(buf, sizeof buf, fp)) != NULL) {
		if (nerr > nerr_maxlimit)
			break;
		token = nexttok(&line);
		if (token == NULL)
			continue;
		
		/*
		 * First is key number.  See if it is okay.
		 */
		keyno = atoi(token);
		if (keyno < 1) {
			log_maybe(&nerr,
				  "authreadkeys: cannot change key %s",
				  token);
			continue;
		}

		if (keyno > NTP_MAXKEY) {
			log_maybe(&nerr,
				  "authreadkeys: key %s > %d reserved for Autokey",
				  token, NTP_MAXKEY);
			continue;
		}

		/*
		 * Next is keytype. See if that is all right.
		 */
		token = nexttok(&line);
		if (token == NULL) {
			log_maybe(&nerr,
				  "authreadkeys: no key type for key %d",
				  keyno);
			continue;
		}

		/* We want to silently ignore keys where we do not
		 * support the requested digest type. OTOH, we want to
		 * make sure the file is well-formed.  That means we
		 * have to process the line completely and have to
		 * finally throw away the result... This is a bit more
		 * work, but it also results in better error detection.
		 */ 
#ifdef OPENSSL
		/*
		 * The key type is the NID used by the message digest 
		 * algorithm. There are a number of inconsistencies in
		 * the OpenSSL database. We attempt to discover them
		 * here and prevent use of inconsistent data later.
		 */
		keytype = keytype_from_text(token, NULL);
		if (keytype == 0) {
			log_maybe(NULL,
				  "authreadkeys: invalid type for key %d",
				  keyno);
#  ifdef ENABLE_CMAC
		} else if (NID_cmac != keytype &&
				EVP_get_digestbynid(keytype) == NULL) {
			log_maybe(NULL,
				  "authreadkeys: no algorithm for key %d",
				  keyno);
			keytype = 0;
#  endif /* ENABLE_CMAC */
		}
#else	/* !OPENSSL follows */
		/*
		 * The key type is unused, but is required to be 'M' or
		 * 'm' for compatibility.
		 */
		if (!(*token == 'M' || *token == 'm')) {
			log_maybe(NULL,
				  "authreadkeys: invalid type for key %d",
				  keyno);
			keytype = 0;
		} else {
			keytype = KEY_TYPE_MD5;
		}
#endif	/* !OPENSSL */

		/*
		 * Finally, get key and insert it. If it is longer than 20
		 * characters, it is a binary string encoded in hex;
		 * otherwise, it is a text string of printable ASCII
		 * characters.
		 */
		token = nexttok(&line);
		if (token == NULL) {
			log_maybe(&nerr,
				  "authreadkeys: no key for key %d", keyno);
			continue;
		}
		next = NULL;
		len = strlen(token);
		if (len <= 20) {	/* Bug 2537 */
			next = emalloc(sizeof(KeyDataT) + len);
			next->keyacclist = NULL;
			next->keyid   = keyno;
			next->keytype = keytype;
			next->seclen  = len;
			memcpy(next->secbuf, token, len);
		} else {
			static const char hex[] = "0123456789abcdef";
			u_char	temp;
			char	*ptr;
			size_t	jlim;

			jlim = min(len, 2 * sizeof(keystr));
			for (j = 0; j < jlim; j++) {
				ptr = strchr(hex, tolower((unsigned char)token[j]));
				if (ptr == NULL)
					break;	/* abort decoding */
				temp = (u_char)(ptr - hex);
				if (j & 1)
					keystr[j / 2] |= temp;
				else
					keystr[j / 2] = temp << 4;
			}
			if (j < jlim) {
				log_maybe(&nerr,
					  "authreadkeys: invalid hex digit for key %d",
					  keyno);
				continue;
			}
			len = jlim/2; /* hmmmm.... what about odd length?!? */
			next = emalloc(sizeof(KeyDataT) + len);
			next->keyacclist = NULL;
			next->keyid   = keyno;
			next->keytype = keytype;
			next->seclen  = len;
			memcpy(next->secbuf, keystr, len);
		}

		token = nexttok(&line);
		if (token != NULL) {	/* A comma-separated IP access list */
			char *tp = token;

			while (tp) {
				char *i;
				char *snp;	/* subnet text pointer */
				unsigned int snbits;
				sockaddr_u addr;

				i = strchr(tp, (int)',');
				if (i) {
					*i = '\0';
				}
				snp = strchr(tp, (int)'/');
				if (snp) {
					char *sp;

					*snp++ = '\0';
					snbits = 0;
					sp = snp;

					while (*sp != '\0') {
						if (!isdigit((unsigned char)*sp))
						    break;
						if (snbits > 1000)
						    break;	/* overflow */
						snbits = 10 * snbits + (*sp++ - '0');       /* ascii dependent */
					}
					if (*sp != '\0') {
						log_maybe(&nerr,
							  "authreadkeys: Invalid character in subnet specification for <%s/%s> in key %d",
							  sp, snp, keyno);
						goto nextip;
					}
				} else {
					snbits = UINT_MAX;
				}

				if (is_ip_address(tp, AF_UNSPEC, &addr)) {
					/* Make sure that snbits is valid for addr */
				    if ((snbits < UINT_MAX) &&
					( (IS_IPV4(&addr) && snbits > 32) ||
					  (IS_IPV6(&addr) && snbits > 128))) {
						log_maybe(NULL,
							  "authreadkeys: excessive subnet mask <%s/%s> for key %d",
							  tp, snp, keyno);
				    }
				    next->keyacclist = keyacc_new_push(
					next->keyacclist, &addr, snbits);
				} else {
					log_maybe(&nerr,
						  "authreadkeys: invalid IP address <%s> for key %d",
						  tp, keyno);
				}

			nextip:
				if (i) {
					tp = i + 1;
				} else {
					tp = 0;
				}
			}
		}

		/* check if this has to be weeded out... */
		if (0 == keytype) {
			free_keydata(next);
			next = NULL;
			continue;
		}
		
		INSIST(NULL != next);
		next->next = list;
		list = next;
	}
	fclose(fp);
	if (nerr > 0) {
		const char * why = "";
		if (nerr > nerr_maxlimit)
			why = " (emergency break)";
		msyslog(LOG_ERR,
			"authreadkeys: rejecting file '%s' after %u error(s)%s",
			file, nerr, why);
		goto onerror;
	}

	/* first remove old file-based keys */
	auth_delkeys();
	/* insert the new key material */
	while (NULL != (next = list)) {
		list = next->next;
		MD5auth_setkey(next->keyid, next->keytype,
			       next->secbuf, next->seclen, next->keyacclist);
		next->keyacclist = NULL; /* consumed by MD5auth_setkey */
		free_keydata(next);
	}
	return (1);

  onerror:
	/* Mop up temporary storage before bailing out. */
	while (NULL != (next = list)) {
		list = next->next;
		free_keydata(next);
	}
	return (0);
}