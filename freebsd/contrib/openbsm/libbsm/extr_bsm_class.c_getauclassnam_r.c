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
struct au_class_ent {int /*<<< orphan*/  ac_name; } ;

/* Variables and functions */
 struct au_class_ent* getauclassent_r_locked (struct au_class_ent*) ; 
 int /*<<< orphan*/  mutex ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  setauclass_locked () ; 
 scalar_t__ strcmp (char const*,int /*<<< orphan*/ ) ; 

struct au_class_ent *
getauclassnam_r(struct au_class_ent *c, const char *name)
{
	struct au_class_ent *cp;

	if (name == NULL)
		return (NULL);

#ifdef HAVE_PTHREAD_MUTEX_LOCK
	pthread_mutex_lock(&mutex);
#endif
	setauclass_locked();
	while ((cp = getauclassent_r_locked(c)) != NULL) {
		if (strcmp(name, cp->ac_name) == 0) {
#ifdef HAVE_PTHREAD_MUTEX_LOCK
			pthread_mutex_unlock(&mutex);
#endif
			return (cp);
		}
	}
#ifdef HAVE_PTHREAD_MUTEX_LOCK
	pthread_mutex_unlock(&mutex);
#endif
	return (NULL);
}