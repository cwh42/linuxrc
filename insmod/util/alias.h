/*
 * This file is split out from config.c for easier editing
 */

/*
 * tbpath and tbtype are used to build the complete set of paths for
 * finding modules.
 */
static char *tbpath[] =
{
	"/lib/modules/VERSION",	/* just a placeholder, look at config_read */
	"/lib/modules/KVERSION",/* just a placeholder, look at config_read */
	"/lib/modules/default",
	"/lib/modules",
	NULL			/* marks the end of the list! */
};

static char *tbtype[] =
{
	"fs",
	"net",
	"scsi",
	"block",
	"cdrom",
	"ipv4",
	"ipv6",
	"sound",
	"fc4",
	"video",
	"misc",
	"pcmcia",
	"atm",
	"usb",
	"ide",
	NULL			/* marks the end of the list! */
};

/*
 * This is the list of pre-defined aliases.
 * Each entry can be overridden by an entry in /etc/modules.conf
 */
char *aliaslist[] =
{
	"binfmt-204 binfmt_aout",
	"binfmt-263 binfmt_aout",
	"binfmt-264 binfmt_aout",
	"binfmt-267 binfmt_aout",
	"binfmt-387 binfmt_aout",
	"binfmt-332 iBCS",
	"binfmt--310 binfmt_java",

	"block-major-1 rd",
	"block-major-2 floppy",
	"block-major-3 ide-probe",
	"block-major-7 loop",
	"block-major-8 sd_mod",
	"block-major-9 md", /* For modular RAID */
	"block-major-11 sr_mod",
	"block-major-13 xd",
	"block-major-15 cdu31a",
	"block-major-16 gscd",
	"block-major-17 optcd",
	"block-major-18 sjcd",
	"block-major-20 mcdx",
	"block-major-22 ide-probe",
	"block-major-23 mcd",
	"block-major-24 sonycd535",
	"block-major-25 sbpcd",
	"block-major-26 sbpcd",
	"block-major-27 sbpcd",
	"block-major-29 aztcd",
	"block-major-32 cm206",
	"block-major-33 ide-probe",
	"block-major-34 ide-probe",
	"block-major-37 ide-tape",

	"char-major-4 serial",
	"char-major-5 serial",
	"char-major-6 lp",
	"char-major-9 st",
	"char-major-10 off",		/* was: mouse, was: misc */
	"char-major-10-0 busmouse",	/* /dev/logibm Logitech bus mouse */
	"char-major-10-1 psaux",	/* /dev/psaux PS/2-style mouse port */
	"char-major-10-2 msbusmouse",	/* /dev/inportbm Microsoft Inport bus mouse */
	"char-major-10-3 atixlmouse",	/* /dev/atibm ATI XL bus mouse */
 					/* /dev/jbm J-mouse */
 					/* /dev/amigamouse Amiga mouse (68k/Amiga) */
 					/* /dev/atarimouse Atari mouse */
 					/* /dev/sunmouse Sun mouse */
 					/* /dev/beep Fancy beep device */
 					/* /dev/modreq Kernel module load request */
	"char-major-10-130 wdt",	/* /dev/watchdog Watchdog timer port */
	"char-major-10-131 wdt",	/* /dev/temperature Machine internal temperature */
 					/* /dev/hwtrap Hardware fault trap */
 					/* /dev/exttrp External device trap */
	"char-major-10-135 off",	/* rtc cannot be compiled as a module */
	"char-major-10-139 openprom",	/* /dev/openprom Linux/Sparc interface */
	"char-major-10-144 nvram", /* from Tigran Aivazian <tigran@sco.COM> */
	 
	"char-major-14 soundcore",
	"char-major-19 cyclades",
	"char-major-20 cyclades",
	"char-major-21 sg",
	"char-major-22 pcxx", /* ?? */
	"char-major-23 pcxx", /* ?? */
	"char-major-27 ftape",
	"char-major-34 scc",
	"char-major-35 tclmidi",
	"char-major-36 netlink",
	"char-major-37 ide-tape",
	"char-major-48 riscom8",
	"char-major-49 riscom8",
	"char-major-57 esp",
	"char-major-58 esp",
	"char-major-63 kdebug",
	"char-major-99 ppdev",
	"char-major-107 3dfx", /* from Tigran Aivazian <tigran@sco.COM> */

	"dos msdos",
	"dummy0 dummy",
	"dummy1 dummy",
	"eth0 off",
	"iso9660 isofs",
	"md-personality-1 linear",
	"md-personality-2 raid0",
	"net-pf-1 unix",	/* PF_UNIX	1  Unix domain sockets */
	"net-pf-2 ipv4",	/* PF_INET	2  Internet IP Protocol */
	"net-pf-3 off",		/* PF_AX25	3  Amateur Radio AX.25 */
	"net-pf-4 off",		/* PF_IPX	4  Novell IPX */
	"net-pf-5 off",		/* PF_APPLETALK	5  Appletalk DDP */
 	"net-pf-6 off",		/* PF_NETROM	6  Amateur radio NetROM */
 				/* PF_BRIDGE	7  Multiprotocol bridge */
 				/* PF_AAL5	8  Reserved for Werner's ATM */
 				/* PF_X25	9  Reserved for X.25 project */
 				/* PF_INET6	10 IP version 6 */

	/* next two from <dairiki@matthews.dairiki.org>  Thanks! */
	"net-pf-17 af_packet",
	"net-pf-19 off",	/* acorn econet */

	"netalias-2 ip_alias",
	"plip0 plip",
	"plip1 plip",
	"ppp0 ppp",
	"ppp1 ppp",
	"scsi_hostadapter off",	/* if not in config file */
	"slip0 slip",
	"slip1 slip",
	"tty-ldisc-1 slip",
	"tty-ldisc-3 ppp",
	"ppp-compress-21 bsd_comp",
	"ppp-compress-24 ppp_deflate",
	"ppp-compress-26 ppp_deflate",

	"parport_lowlevel parport_pc",

	NULL			/* marks the end of the list! */
};

/*
 * This is the list of pre-defined options.
 * Each entry can be overridden by an entry in /etc/modules.conf
 */
char *optlist[] =
{
	"dummy0 -o dummy0",
	"dummy1 -o dummy1",
	"sb io=0x220 irq=7 dma=1 dma16=5 mpu_io=0x330",
	NULL			/* marks the end of the list! */
};

/*
 * This is the list of pre-defined "above"s,
 * used for pull-in of additional modules
 * Each entry can be overridden by an entry in /etc/modules.conf
 */
char *above[] =
{
	NULL			/* marks the end of the list! */
};

/*
 * This is the list of pre-defined "below"s,
 * used for push-in of additional modules
 * Each entry can be overridden by an entry in /etc/modules.conf
 */
char *below[] =
{
	NULL			/* marks the end of the list! */
};