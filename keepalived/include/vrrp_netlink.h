/*
 * Soft:        Keepalived is a failover program for the LVS project
 *              <www.linuxvirtualserver.org>. It monitor & manipulate
 *              a loadbalanced server pool using multi-layer checks.
 *
 * Part:        vrrp_netlink.c include file.
 *
 * Version:     $Id: vrrp_netlink.h,v 1.1.14 2007/09/13 21:12:33 acassen Exp $
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

#ifndef _VRRP_NETLINK_H
#define _VRRP_NETLINK_H 1

/* Hack for GNU libc version 2. */
#ifndef MSG_TRUNC
#define MSG_TRUNC      0x20
#endif				/* MSG_TRUNC */

/* global includes */
#include <asm/types.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>

/* local includes */
#include "timer.h"

/* types definitions */
struct nl_handle {
	int fd;
	struct sockaddr_nl snl;
	__u32 seq;
};

/* Define types */
#define NETLINK_TIMER (30 * TIMER_HZ)

/* Global vars exported */
extern struct nl_handle nl_kernel;	/* Kernel reflection channel */
extern struct nl_handle nl_cmd;		/* Command channel */

/* prototypes */
extern int addattr32(struct nlmsghdr *n, int maxlen, int type, uint32_t data_obj);
extern int addattr_l(struct nlmsghdr *n, int maxlen, int type, void *data_obj,
		     int alen);
extern char *netlink_scope_n2a(int scope);
extern int netlink_scope_a2n(char *scope);
extern int netlink_socket(struct nl_handle *nl, unsigned long groups);
extern int netlink_close(struct nl_handle *nl);
extern int netlink_talk(struct nl_handle *nl, struct nlmsghdr *n);
extern int netlink_interface_lookup(void);
extern int netlink_interface_refresh(void);
extern void kernel_netlink_init(void);
extern void kernel_netlink_close(void);

#endif
