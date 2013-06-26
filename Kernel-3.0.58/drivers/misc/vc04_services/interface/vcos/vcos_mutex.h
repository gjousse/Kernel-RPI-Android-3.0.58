/*
 * Copyright (c) 2010-2011 Broadcom. All rights reserved.
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*=============================================================================
VideoCore OS Abstraction Layer - mutex public header file
=============================================================================*/

#ifndef VCOS_MUTEX_H
#define VCOS_MUTEX_H

#ifdef __cplusplus
extern "C" {
#endif

#include "interface/vcos/vcos_types.h"
#include "vcos_platform.h"

/**
 * \file vcos_mutex.h
 *
 * Mutex API. Mutexes are not re-entrant, as supporting this adds extra code
 * that slows down clients which have been written sensibly.
 *
 * \sa vcos_reentrant_mutex.h
 *
 */

/** Create a mutex.
  *
  * @param m      Filled in with mutex on return
  * @param name   A non-null name for the mutex, used for diagnostics.
  *
  * @return VCOS_SUCCESS if mutex was created, or error code.
  */
VCOS_INLINE_DECL
VCOS_STATUS_T vcos_mutex_create(VCOS_MUTEX_T *m, const char *name);

/** Delete the mutex.
  */
VCOS_INLINE_DECL
void vcos_mutex_delete(VCOS_MUTEX_T *m);

/**
  * \brief Wait to claim the mutex.
  *
  * On most platforms this always returns VCOS_SUCCESS, and so would ideally be
  * a void function, however some platforms allow a wait to be interrupted so
  * it remains non-void.
  *
  * Try to obtain the mutex.
  * @param m   Mutex to wait on
  * @return VCOS_SUCCESS - mutex was taken.
  *         VCOS_EAGAIN  - could not take mutex.
  */
#ifndef vcos_mutex_lock
VCOS_INLINE_DECL
VCOS_STATUS_T vcos_mutex_lock(VCOS_MUTEX_T *m);

/** Release the mutex.
  */
VCOS_INLINE_DECL
void vcos_mutex_unlock(VCOS_MUTEX_T *m);
#endif

/** Test if the mutex is already locked.
  *
  * @return 1 if mutex is locked, 0 if it is unlocked.
  */
VCOS_INLINE_DECL
int vcos_mutex_is_locked(VCOS_MUTEX_T *m);

/** Obtain the mutex if possible.
  *
  * @param m  the mutex to try to obtain
  *
  * @return VCOS_SUCCESS if mutex is succesfully obtained, or VCOS_EAGAIN
  * if it is already in use by another thread.
  */
#ifndef vcos_mutex_trylock
VCOS_INLINE_DECL
VCOS_STATUS_T vcos_mutex_trylock(VCOS_MUTEX_T *m);
#endif


#ifdef __cplusplus
}
#endif
#endif
