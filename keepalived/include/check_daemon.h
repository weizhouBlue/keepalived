/*
 * Soft:        Keepalived is a failover program for the LVS project
 *              <www.linuxvirtualserver.org>. It monitor & manipulate
 *              a loadbalanced server pool using multi-layer checks.
 *
 * Part:        check_daemon.c include file.
 * 
 * Version:     $Id: check_daemon.h,v 1.1.14 2007/09/13 21:12:33 acassen Exp $
 * 
 * Author:      Alexandre Cassen, <acassen@linux-vs.org>
 *              
 *              This program is distributed in the hope that it will be useful,
 *              but WITHOUT ANY WARRANTY; without even the implied warranty of
 *              MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *              See the GNU General Public License for more details.
 *              
 *              This program is free software; you can redistribute it and/or
 *              modify it under the terms of the GNU General Public License
 *              as published by the Free Software Foundation; either version
 *              2 of the License, or (at your option) any later version.
 *
 * Copyright (C) 2001-2007 Alexandre Cassen, <acassen@freebox.fr>
 */

#ifndef _CHECK_DAEMON_H
#define _CHECK_DAEMON_H

/* system include */
#include <stdlib.h>
#include <signal.h>

/* Daemon define */
#define PROG_CHECK	"Keepalived_healthcheckers"
#define WDOG_CHECK	"/tmp/.healthcheckers"

/* Prototypes */
extern int start_check_child(void);

#endif
