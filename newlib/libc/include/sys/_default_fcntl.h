/* Copyright (c) 2007 Jeff Johnston  <jjohnstn@redhat.com> */

#ifndef	_SYS__DEFAULT_FCNTL_H_
#define	_SYS__DEFAULT_FCNTL_H_
#include <sys/cdefs.h>
#include <sys/_types.h>

_BEGIN_STD_C

#ifndef _MODE_T_DECLARED
typedef	__mode_t	mode_t;		/* permissions */
#define	_MODE_T_DECLARED
#endif
#ifndef _OFF_T_DECLARED
typedef	__off_t		off_t;		/* file offset */
#define	_OFF_T_DECLARED
#endif
#ifndef _PID_T_DECLARED
typedef	__pid_t		pid_t;		/* process id */
#define	_PID_T_DECLARED
#endif
#ifndef _OFF64_T_DECLARED
typedef __off64_t       off64_t;        /* 64-bit file offset */
#define	_OFF64_T_DECLARED
#endif

#define	_FOPEN		(-1)	/* from sys/file.h, kernel use only */
#define	_FREAD		0x0001	/* read enabled */
#define	_FWRITE		0x0002	/* write enabled */
#define	_FAPPEND	0x0400	/* append (writes guaranteed at the end) */
#define	_FMARK		0x0010	/* internal; mark during gc() */
#define	_FDEFER		0x0020	/* internal; defer for next gc pass */
#define	_FASYNC		0x0008	/* signal pgrp when data ready */
#define	_FSHLOCK	0x0080	/* BSD flock() shared lock present */
#define	_FEXLOCK	0x0100	/* BSD flock() exclusive lock present */
#define	_FCREAT		0x0040	/* open with file create */
#define	_FTRUNC		0x0200	/* open with truncation */
#define	_FEXCL		0x0800	/* error on open if file exists */
#define	_FNBIO		0x1000	/* non blocking I/O (sys5 style) */
#define	_FSYNC		0x2000	/* do all writes synchronously */
#define	_FNONBLOCK	0x4000	/* non blocking I/O (POSIX style) */
#define	_FNDELAY	_FNONBLOCK	/* non blocking I/O (4.2 style) */
#define	_FNOCTTY	0x8000	/* don't assign a ctty on this open */
#define	_FNOINHERIT	0x40000
#define	_FDIRECT	0x80000
#define	_FNOFOLLOW	0x100000
#define	_FDIRECTORY	0x200000
#define	_FEXECSRCH	0x400000

#define	O_ACCMODE	(O_RDONLY|O_WRONLY|O_RDWR)

/*
 * Flag values for open(2) and fcntl(2)
 * The kernel adds 1 to the open modes to turn it into some
 * combination of FREAD and FWRITE.
 */
#define	O_RDONLY	0		/* +1 == FREAD */
#define	O_WRONLY	1		/* +1 == FWRITE */
#define	O_RDWR		2		/* +1 == FREAD|FWRITE */
#define	O_APPEND	_FAPPEND
#define	O_CREAT		_FCREAT
#define	O_TRUNC		_FTRUNC
#define	O_EXCL		_FEXCL
#define O_SYNC		_FSYNC
/*	O_NDELAY	_FNDELAY 	set in include/fcntl.h */
/*	O_NDELAY	_FNBIO 		set in include/fcntl.h */
#define	O_NONBLOCK	_FNONBLOCK
#define	O_NOCTTY	_FNOCTTY

/* POSIX-1.2008 specific flags */
#if __POSIX_VISIBLE >= 200809
#define	O_CLOEXEC	_FNOINHERIT
#define	O_NOFOLLOW	_FNOFOLLOW
#define	O_DIRECTORY	_FDIRECTORY
#define	O_EXEC		_FEXECSRCH
#define	O_SEARCH	_FEXECSRCH
#endif

#if __BSD_VISIBLE
#define	O_DIRECT	_FDIRECT
#endif

#define O_DSYNC         _FSYNC
#define O_RSYNC         _FSYNC

#if __MISC_VISIBLE

/*
 * Flags that work for fcntl(fd, F_SETFL, FXXXX)
 */
#define	FAPPEND		_FAPPEND
#define	FSYNC		_FSYNC
#define	FASYNC		_FASYNC
#define	FNBIO		_FNBIO
#define	FNONBIO		_FNONBLOCK	/* XXX fix to be NONBLOCK everywhere */
#define	FNDELAY		_FNDELAY

/*
 * Flags that are disallowed for fcntl's (FCNTLCANT);
 * used for opens, internal state, or locking.
 */
#define	FREAD		_FREAD
#define	FWRITE		_FWRITE
#define	FMARK		_FMARK
#define	FDEFER		_FDEFER
#define	FSHLOCK		_FSHLOCK
#define	FEXLOCK		_FEXLOCK

/*
 * The rest of the flags, used only for opens
 */
#define	FOPEN		_FOPEN
#define	FCREAT		_FCREAT
#define	FTRUNC		_FTRUNC
#define	FEXCL		_FEXCL
#define	FNOCTTY		_FNOCTTY

#endif	/* __MISC_VISIBLE */

#if __BSD_VISIBLE
#define	FNONBLOCK	_FNONBLOCK
#endif	/* __BSD_VISIBLE */

/* XXX close on exec request; must match UF_EXCLOSE in user.h */
#define	FD_CLOEXEC	1	/* posix */

/* fcntl(2) requests */
#define	F_DUPFD		0	/* Duplicate fildes */
#define	F_GETFD		1	/* Get fildes flags (close on exec) */
#define	F_SETFD		2	/* Set fildes flags (close on exec) */
#define	F_GETFL		3	/* Get file flags */
#define	F_SETFL		4	/* Set file flags */
#if __BSD_VISIBLE || __POSIX_VISIBLE >= 200112
#define	F_GETOWN 	5	/* Get owner - for ASYNC */
#define	F_SETOWN 	6	/* Set owner - for ASYNC */
#endif /* __BSD_VISIBLE || __POSIX_VISIBLE >= 200112 */
#define	F_GETLK  	7	/* Get record-locking information */
#define	F_SETLK  	8	/* Set or Clear a record-lock (Non-Blocking) */
#define	F_SETLKW 	9	/* Set or Clear a record-lock (Blocking) */
#if __MISC_VISIBLE
#define	F_RGETLK 	10	/* Test a remote lock to see if it is blocked */
#define	F_RSETLK 	11	/* Set or unlock a remote lock */
#define	F_CNVT 		12	/* Convert a fhandle to an open fd */
#define	F_RSETLKW 	13	/* Set or Clear remote record-lock(Blocking) */
#endif	/* __MISC_VISIBLE */
#if __POSIX_VISIBLE >= 200809
#define	F_DUPFD_CLOEXEC	14	/* As F_DUPFD, but set close-on-exec flag */
#endif

/* fcntl(2) flags (l_type field of flock structure) */
#define	F_RDLCK		1	/* read lock */
#define	F_WRLCK		2	/* write lock */
#define	F_UNLCK		3	/* remove lock(s) */
#if __MISC_VISIBLE
#define	F_UNLKSYS	4	/* remove remote locks for a given system */
#endif	/* __MISC_VISIBLE */

#if __BSD_VISIBLE || __POSIX_VISIBLE >= 200809
/* Special descriptor value to denote the cwd in calls to openat(2) etc. */
#define AT_FDCWD -2

/* Flag values for faccessat2) et al. */
#define AT_EACCESS                 0x0001
#define AT_SYMLINK_NOFOLLOW        0x0002
#define AT_SYMLINK_FOLLOW          0x0004
#define AT_REMOVEDIR               0x0008
#if __GNU_VISIBLE
#define AT_EMPTY_PATH              0x0010
#define _AT_NULL_PATHNAME_ALLOWED  0x4000 /* Internal flag used by futimesat */
#endif
#endif

#if __BSD_VISIBLE
/* lock operations for flock(2) */
#define	LOCK_SH		0x01		/* shared file lock */
#define	LOCK_EX		0x02		/* exclusive file lock */
#define	LOCK_NB		0x04		/* don't block when locking */
#define	LOCK_UN		0x08		/* unlock file */
#endif

/* file segment locking set data type - information passed to system by user */
struct flock {
	short	l_type;		/* F_RDLCK, F_WRLCK, or F_UNLCK */
	short	l_whence;	/* flag to choose starting offset */
	long	l_start;	/* relative offset, in bytes */
	long	l_len;		/* length, in bytes; 0 means lock to EOF */
	short	l_pid;		/* returned with F_GETLK */
	short	l_xxx;		/* reserved for future use */
};

#if __MISC_VISIBLE
/* extended file segment locking set data type */
struct eflock {
	short	l_type;		/* F_RDLCK, F_WRLCK, or F_UNLCK */
	short	l_whence;	/* flag to choose starting offset */
	long	l_start;	/* relative offset, in bytes */
	long	l_len;		/* length, in bytes; 0 means lock to EOF */
	short	l_pid;		/* returned with F_GETLK */
	short	l_xxx;		/* reserved for future use */
	long	l_rpid;		/* Remote process id wanting this lock */
	long	l_rsys;		/* Remote system id wanting this lock */
};
#endif	/* __MISC_VISIBLE */

extern int open (const char *, int, ...);
#if __ATFILE_VISIBLE
extern int openat (int, const char *, int, ...);
#endif
extern int creat (const char *, mode_t);
extern int fcntl (int, int, ...);
#if __BSD_VISIBLE
extern int flock (int, int);
#endif

/* Provide _<systemcall> prototypes for functions provided by some versions
   of newlib.  */
#ifdef _LIBC
extern int open (const char *, int, ...);
extern int fcntl (int, int, ...);
#ifdef __LARGE64_FILES
extern int open64 (const char *, int, ...);
#endif
#endif

_END_STD_C

#endif	/* !_SYS__DEFAULT_FCNTL_H_ */
