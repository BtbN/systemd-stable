/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include "manager.h"

int manager_varlink_init(Manager *m);
void manager_varlink_done(Manager *m);

/* Creates a new VarlinkServer and binds methods. Does not set up sockets or attach events.
 * Used for manager serialize/deserialize. */
int manager_setup_varlink_server(Manager *m, VarlinkServer **ret_s);

/* The manager is expected to send an update to systemd-oomd if one of the following occurs:
 * - The value of ManagedOOM*= properties change
 * - A unit with ManagedOOM*= properties changes unit active state */
int manager_varlink_send_managed_oom_update(Unit *u);
