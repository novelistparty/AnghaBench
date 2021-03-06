#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  u_char ;
struct g_raid3_metadata {scalar_t__ md_version; scalar_t__ md_sectorsize; int /*<<< orphan*/  md_magic; } ;
struct g_provider {int /*<<< orphan*/  name; scalar_t__ sectorsize; scalar_t__ mediasize; } ;
struct g_consumer {struct g_provider* provider; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  G_RAID3_DEBUG (int,char*,...) ; 
 int /*<<< orphan*/  G_RAID3_MAGIC ; 
 scalar_t__ G_RAID3_VERSION ; 
 scalar_t__ MAXPHYS ; 
 int g_access (struct g_consumer*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  g_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * g_read_data (struct g_consumer*,scalar_t__,scalar_t__,int*) ; 
 int /*<<< orphan*/  g_topology_assert () ; 
 int /*<<< orphan*/  g_topology_lock () ; 
 int /*<<< orphan*/  g_topology_unlock () ; 
 int raid3_metadata_decode (int /*<<< orphan*/ *,struct g_raid3_metadata*) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
g_raid3_read_metadata(struct g_consumer *cp, struct g_raid3_metadata *md)
{
	struct g_provider *pp;
	u_char *buf;
	int error;

	g_topology_assert();

	error = g_access(cp, 1, 0, 0);
	if (error != 0)
		return (error);
	pp = cp->provider;
	g_topology_unlock();
	/* Metadata are stored on last sector. */
	buf = g_read_data(cp, pp->mediasize - pp->sectorsize, pp->sectorsize,
	    &error);
	g_topology_lock();
	g_access(cp, -1, 0, 0);
	if (buf == NULL) {
		G_RAID3_DEBUG(1, "Cannot read metadata from %s (error=%d).",
		    cp->provider->name, error);
		return (error);
	}

	/* Decode metadata. */
	error = raid3_metadata_decode(buf, md);
	g_free(buf);
	if (strcmp(md->md_magic, G_RAID3_MAGIC) != 0)
		return (EINVAL);
	if (md->md_version > G_RAID3_VERSION) {
		G_RAID3_DEBUG(0,
		    "Kernel module is too old to handle metadata from %s.",
		    cp->provider->name);
		return (EINVAL);
	}
	if (error != 0) {
		G_RAID3_DEBUG(1, "MD5 metadata hash mismatch for provider %s.",
		    cp->provider->name);
		return (error);
	}
	if (md->md_sectorsize > MAXPHYS) {
		G_RAID3_DEBUG(0, "The blocksize is too big.");
		return (EINVAL);
	}

	return (0);
}