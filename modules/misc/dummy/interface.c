/*****************************************************************************
 * intf_dummy.c: dummy interface plugin
 *****************************************************************************
 * Copyright (C) 2000, 2001 the VideoLAN team
 * $Id$
 *
 * Authors: Samuel Hocevar <sam@zoy.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

/*****************************************************************************
 * Preamble
 *****************************************************************************/
#include <string.h>

#include <vlc/vlc.h>
#include <vlc_interface.h>

#include "dummy.h"

/*****************************************************************************
 * Open: initialize dummy interface
 *****************************************************************************/
int  E_(OpenIntf) ( vlc_object_t *p_this )
{
    intf_thread_t *p_intf = (intf_thread_t*) p_this;

#ifdef WIN32
    vlc_bool_t b_quiet;
    b_quiet = config_GetInt( p_intf, "dummy-quiet" );
    if( !b_quiet )
        CONSOLE_INTRO_MSG;
#endif

    msg_Info( p_intf, "using the dummy interface module..." );

    p_intf->pf_run = NULL;

    return VLC_SUCCESS;
}
