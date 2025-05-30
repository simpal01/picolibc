/*
 * Support file for amdgcn in newlib.
 * Copyright (c) 2014-2017 Mentor Graphics.
 *
 * The authors hereby grant permission to use, copy, modify, distribute,
 * and license this software and its documentation for any purpose, provided
 * that existing copyright notices are retained in all copies and that this
 * notice is included verbatim in any distributions. No written agreement,
 * license, or royalty fee is required for any of the authorized uses.
 * Modifications to this software may be copyrighted by their authors
 * and need not follow the licensing terms described here, provided that
 * the new terms are clearly indicated on the first page of each file where
 * they apply.
 */

#include <picolibc.h>

#include <unistd.h>
#include <signal.h>
#include "exit-value.h"

void __noreturn
abort (void)
{
  write (2, "GCN Kernel Aborted\n", 19);
  exit_with_status_and_signal (0, SIGABRT);
}
