
/* ------------------------ usrinc/wsadmin.h ------------------ */
/*								                                */
/*              Copyright (c) 2000 TmaxSoft Co., Ltd	           */
/*                   All Rights Reserved  			            */
/*								                                */
/* ------------------------------------------------------------ */

#ifndef _WEBTOB_WSADMIN_H
#define _WEBTOB_WSADMIN_H
#define _WSADMIN_VERSION	10800	/* 01.06.00 */

#include <sys/types.h>
#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#define __cdecl
#endif

/* 
   WSADMIN COMMANDS 
 */

/* simple commands */
#define WSADM_DISCON		1	/* client disconnect */
#define WSADM_CLIINFO		2	/* client information */
#define WSADM_QPURGE		3	/* server q purge */
#define WSADM_BOOT		4	/* wsboot */
#define WSADM_DOWN		5	/* wsdown */
#define WSADM_SUSPEND		6	/* suspend process */
#define WSADM_RESUME		7	/* resume process */
#define WSADM_RESTAT		8	/* reset statistics */

/* statistics */
#define WSADM_SVC_STAT		101
#define WSADM_SPR_STAT		102
#define WSADM_SVR_STAT		103

/* configuration */
#define WSADM_WEBTOB_INFO	201
#define WSADM_DOMAIN_CONF	202
#define WSADM_NODE_CONF		203
#define WSADM_VHOST_CONF	204
#define WSADM_SVG_CONF		205
#define WSADM_SVR_CONF		206
#define WSADM_SVC_CONF		207

/* wsadmin option flags */
#ifndef TPNOFLAGS
#define TPNOFLAGS       0x00000000
#endif
#define WSADM_AFLAG	0x00000001	/* ALL */
#define WSADM_CFLAG	0x00000002	/* HTH or Client */
#define WSADM_FFLAG	0x00000004	/* Force */
#define WSADM_GFLAG	0x00000008	/* SVG or Gateway */
#define WSADM_IFLAG	0x00000010	/* Immediate or Idle */
#define WSADM_NFLAG	0x00000020	/* Not Ready or Node or Number */
#define WSADM_PFLAG	0x00000040	/* Server Process */
#define WSADM_SFLAG	0x00000100	/* SVR or SVC */
#define WSADM_VFLAG	0x00000400	/* SVR */

/* ETC macros */
#define MAX_NUM_PORTNO		10	/* >= MAX_LISTEN	*/
#define MAX_NUM_HTH		100	/* >= MAX_HTTP_HTH	*/

#define WEBTOB_NAME_SIZE	32	/* >= max(*_NAME_SIZE)	*/
#define WEBTOB_HOST_NAME_SIZE	128
#define WEBTOB_PATH_LENGTH	256
#define WEBTOB_CLOPT_LENGTH	256
#define WEBTOB_DBINFO_SIZE	256
#define WEBTOB_URL_SIZE		512

#define MAX_VHOST_STRING_SIZE   4096

/* Fixed header structure */
struct wsadm_header {
	int	version;	/* I: _WSADMIN_VERSION */
	int	size;		/* I: total buffer size */
	int	offset;		/* I: fetch offset */
	int	num_entry;	/* O: number of fetched entries */
	int	num_left;	/* O: number of entries to fetch */
	int	opt_int;	/* I: optional integer argument */
	int	reserve_int[2];			
	char	opt_char[WEBTOB_NAME_SIZE]; /* I: optinal string */
};


/* WSADM_DOMAIN_CONF return structures */
struct wsadm_domain_conf_body {
	char	name[WEBTOB_NAME_SIZE];	/* domain name */
	int	reserve_int2[2];
	int	nliveinq;
	int	nhthchktime;
	int	domainid;
	int	nodecpc;
	int	reserve_int3[4];			/* reserved */
	/* --- maximum configuration values --- */
	int	maxsvc;
	/* ----- other information -----  */
	int	no;				/* reserved */
	int	reserve_int1[2];
};

struct wsadm_domain_conf {
	/* fixed header */
	struct wsadm_header header;
	/* fixed body */
	struct wsadm_domain_conf_body body;
};


/* WSADM_NODE_CONF return structures */
struct wsadm_node_conf_body {
	char	name[WEBTOB_NAME_SIZE];
	char	user[WEBTOB_NAME_SIZE];
	char	group[WEBTOB_NAME_SIZE];
	char	hostname[WEBTOB_HOST_NAME_SIZE];
	unsigned int ip;
	char	admin[WEBTOB_HOST_NAME_SIZE];
	char	docroot[WEBTOB_PATH_LENGTH];
	char	svrroot[WEBTOB_PATH_LENGTH];
	char	method[WEBTOB_PATH_LENGTH];
	int	shmkey;
	int	hth;
	int	hthqtimeout;
	int	nodeport;
	int	port[MAX_NUM_PORTNO];
	char	listen[WEBTOB_PATH_LENGTH];
	int	httpjeusport;
	int	jsvport;
#if (_WSADMIN_VERSION+0>=10600)
	int	jsvsslport;
	int	jsvsslflag;
	char	jsvsslname[WEBTOB_NAME_SIZE];
#endif
	int	racport;
	int	sslflag;
	char	sslname[WEBTOB_NAME_SIZE];
	int	keepalivetimeout;
	int	keepalivemax;
	int	timeout;
#if (_WSADMIN_VERSION+0>=10700)
	int	initialconnectiontimeout;
#endif
#if (_WSADMIN_VERSION+0>=10500)
	int	requestheadertimeout;
	int	requestbodytimeout;
#endif
	int	clichkintval;
	int	cachesize; /* for backward compatibility */
	int	maxcachememorysize;
	int	cachekey;
	int	cacheentry;
	int	cachemaxfilesize;
	int	cacherefreshimage;
	int	cacherefreshhtml;
	int	cacherefreshdir;
	int	cacherefreshjsv;
	int	cacherefreshrproxy;
	int	requestringbufsize;
	int	maxuser;
	char	webtobdir[WEBTOB_PATH_LENGTH];
	char	appdir[WEBTOB_PATH_LENGTH];
	char	pathdir[WEBTOB_PATH_LENGTH];
	char	reserve_str1[WEBTOB_PATH_LENGTH];
	char	syslogdir[WEBTOB_PATH_LENGTH];
	char	usrlogdir[WEBTOB_PATH_LENGTH];
	char	icondir[WEBTOB_PATH_LENGTH];
	char	userdir[WEBTOB_PATH_LENGTH];
	char	envfile[WEBTOB_PATH_LENGTH];
	char	wsmopt[WEBTOB_PATH_LENGTH];
	char	hthopt[WEBTOB_PATH_LENGTH];
	char	indexname[WEBTOB_PATH_LENGTH];
	char	dirindex[WEBTOB_NAME_SIZE];
	char	options[WEBTOB_PATH_LENGTH];
	char	errordocument[WEBTOB_PATH_LENGTH];
	char	languageprio[WEBTOB_PATH_LENGTH];
	char	logging[WEBTOB_PATH_LENGTH];
	char	errorlog[WEBTOB_PATH_LENGTH];
	char	nodetype[WEBTOB_NAME_SIZE];
	/* ----- other information -----  */
	int	no;
	int	shmsize;
	int	curhth;
	int	hth_maxuser;
	int	vhostcount;
	int	svgcount;
	int	svrcount;
	int	svccount;
	int	maxsprs;
	int	reserve_int1;
	int	totalcpc;
	int	clicount[MAX_NUM_HTH];
	int	reserve_int[4];			/* reserved */
	char	reserve_str[WEBTOB_NAME_SIZE];	/* reserved */
};

struct wsadm_node_conf {
	/* fixed header */
	struct wsadm_header header;
	/* fixed body */
	struct wsadm_node_conf_body body;
};

/* WSADM_VHOST_CONF return structures */
struct wsadm_vhost_conf_body {
	char	name[WEBTOB_NAME_SIZE];
	char	nodename[WEBTOB_NAME_SIZE];
	char	user[WEBTOB_NAME_SIZE];
	char	group[WEBTOB_NAME_SIZE];
	char	hostname[WEBTOB_HOST_NAME_SIZE];
	char	hostalias[WEBTOB_PATH_LENGTH];
	char	admin[WEBTOB_HOST_NAME_SIZE];
	char	docroot[WEBTOB_PATH_LENGTH];
	char	method[WEBTOB_PATH_LENGTH];
	int	port[MAX_NUM_PORTNO];
	char	listen[WEBTOB_PATH_LENGTH];
	int	sslflag;
	char	sslname[WEBTOB_NAME_SIZE];
	char	appdir[WEBTOB_PATH_LENGTH];
	char	usrlogdir[WEBTOB_PATH_LENGTH];
	char	icondir[WEBTOB_PATH_LENGTH];
	char	userdir[WEBTOB_PATH_LENGTH];
	char	envfile[WEBTOB_PATH_LENGTH];
	char	indexname[WEBTOB_PATH_LENGTH];
	char	dirindex[WEBTOB_NAME_SIZE];
	char	options[WEBTOB_PATH_LENGTH];
	char	errordocument[WEBTOB_PATH_LENGTH];
	char	logging[WEBTOB_PATH_LENGTH];
	char	errorlog[WEBTOB_PATH_LENGTH];
	/* ----- other information -----  */
	int	no;
	char	reserve_str[WEBTOB_NAME_SIZE];	/* reserved */
};

struct wsadm_vhost_conf {
	/* fixed header */
	struct wsadm_header header;
	/* fixed body */
	struct wsadm_vhost_conf_body vhost[1];
};

/* WSADM_SVG_CONF return structures */
struct wsadm_svg_conf_body {
	char	name[WEBTOB_NAME_SIZE];
	char	nodename[WEBTOB_NAME_SIZE];
	char	vhostname[MAX_VHOST_STRING_SIZE];
	char	svrtype[WEBTOB_NAME_SIZE];
	char	cousin[WEBTOB_PATH_LENGTH];
	char	backup[WEBTOB_PATH_LENGTH];
	int	load;
	char	appdir[WEBTOB_PATH_LENGTH];
	char	usrlogdir[WEBTOB_PATH_LENGTH];
	char	reserve_str1[WEBTOB_NAME_SIZE];
	char	reserve_str2[WEBTOB_DBINFO_SIZE];
	char	reserve_str3[WEBTOB_DBINFO_SIZE];
	int	reserve_int1[2];
	char	reserve_str4[WEBTOB_NAME_SIZE];
	char	envfile[WEBTOB_PATH_LENGTH];
	char	authentname[WEBTOB_NAME_SIZE];
	char	logging[WEBTOB_PATH_LENGTH];
	char	scriptloc[WEBTOB_PATH_LENGTH];
#if (_WSADMIN_VERSION+0>=10800)
	char	scriptargs[WEBTOB_PATH_LENGTH];
#endif
	/* ----- other information -----  */
	int	no;
	int	reserve_int[5];			/* reserved */
};

struct wsadm_svg_conf {
	/* fixed header */
	struct wsadm_header header;
	/* variable length body */
	struct wsadm_svg_conf_body svg[1];
};


/* WSADM_SVR_CONF return structures */
struct wsadm_svr_conf_body {
	char	name[WEBTOB_NAME_SIZE];
	char	svgname[WEBTOB_NAME_SIZE];
	char	clopt[WEBTOB_CLOPT_LENGTH];
	int	seqno;
	int	minproc;
	int	maxproc;
	char	usrlogdir[WEBTOB_PATH_LENGTH];
	char	uridir[WEBTOB_PATH_LENGTH];
	int	reserve_int1;
	int	maxqcount;
	char	maxqurl[WEBTOB_PATH_LENGTH];
	int	asqcount;
	int	flowcontrol;
	int	maxrestart;
	int	svrcpc;
	char	svrtype[WEBTOB_NAME_SIZE];
	int	httpoutbufsize;
	int	httpinbufsize;
	/* ----- other information -----  */
	int	no;
	int	svgno;
	int	curproc;
	int	reserve_int[4];			/* reserved */
	char	reserve_str[WEBTOB_NAME_SIZE];	/* reserved */
};

struct wsadm_svr_conf {
	/* fixed header */
	struct wsadm_header header;
	/* variable length body */
	struct wsadm_svr_conf_body svr[1];
};


/* WSADM_SVC_CONF return structures */
struct wsadm_svc_conf_body {
	char	name[WEBTOB_NAME_SIZE];
	char	svrname[WEBTOB_NAME_SIZE];
	int	priority;
	int	svctime;
	/* ----- other information -----  */
	int	svri;	/* -1 means this node does not support this svc */
	int	reserve_int[2];			/* reserved */
	char	reserve_str[WEBTOB_NAME_SIZE];	/* reserved */
};

struct wsadm_svc_conf {
	/* fixed header */
	struct wsadm_header header;
	/* variable length body */
	struct wsadm_svc_conf_body svc[1];
};


/* WSADM_WEBTOB_INFO return structures */
struct wsadm_webtob_info_body {
	int	sysinfo;	/* OS version */
	int	version;	/* major*1000000 + minor*1000 + patch */
	int	expdate;	/* if demo license year*10000 + month*100 + day,
				   otherwise 0 */
	int	maxuser;	/* if unlimited, maxuser = -1 */
	int	nodecount;
	int	vhostcount;
	int	svgcount;
	int	svrcount;
	int	svccount;
	int	reserve_int1[4];
	int	dircount;
	int	uricount;
	int	aliascount;
	int	dirindcount;
	int	logcount;
	int	authentcount;
	int	extcount;
	int	sslcount;
	int	errdoccount;
	int	redirectcount;
	int	cousin_group_count;	/* cousin group count: svg  */
	int	cousin_elem_count;
	int	backup_group_count;	/* backup group count: svg */
	int	backup_elem_count;
	int	reserve[6];
};

struct wsadm_node_summary {
	int	no;		/* node number */
	int	nodeport;
	int	racport;
	int	shmkey;
	int	shmsize;
	int	hth;
	unsigned int	ip;
	char	name[WEBTOB_NAME_SIZE];
	int	reserve[4];
};

struct wsadm_webtob_info {
	/* fixed header */
	struct wsadm_header header;
	/* fixed body */
	struct wsadm_webtob_info_body body;
	/* variable length body */
	struct wsadm_node_summary node[1];
};


/* WSADM_SVC_STAT return structures */
struct wsadm_svc_stat_body {
	int	no;
	int	hthno;
	int	count;
	int	cq_count;
	int	aq_count;
	int	reserve_int[3];
	float	average;
	float	q_average;
	char	name[WEBTOB_NAME_SIZE];
	char	status[WEBTOB_NAME_SIZE];
	/* char	reserve_str[WEBTOB_NAME_SIZE*2]; */
};

struct wsadm_svc_stat {
	/* fixed header */
	struct wsadm_header header;
	/* variable length body */
	struct wsadm_svc_stat_body svc[1];
};


/* WSADM_SPR_STAT return structures */
struct wsadm_spr_stat_body {
	int	no;
	int	hthno;
	int	count;
	int	pid;
	int	clid;
	int	clid_ex;
	float	running_time;
	float	average;
	char	name[WEBTOB_NAME_SIZE];
	char	svgname[WEBTOB_NAME_SIZE];
	char	status[WEBTOB_NAME_SIZE];
	char	service[WEBTOB_NAME_SIZE];
#if (_WSADMIN_VERSION+0>=10300)
	char	request_url[WEBTOB_URL_SIZE];	/* <host>:<port>/<path> */
#endif
};

struct wsadm_spr_stat {
	/* fixed header */
	struct wsadm_header header;
	/* variable length body */
	struct wsadm_spr_stat_body spr[1];
};


/* WSADM_SVR_STAT return structures */
struct wsadm_svr_stat_body {
	int	svri;
	int	hthno;
	int	count;
	int	qcount;
	int	qpcount;
	int	emcount;
	int	asqcount;
	int	reserve_int;
	char	name[WEBTOB_NAME_SIZE];
	char	status[WEBTOB_NAME_SIZE];
	char	reserve_str[WEBTOB_NAME_SIZE*2];
};

struct wsadm_svr_stat {
	/* fixed header */
	struct wsadm_header header;
	/* variable length body */
	struct wsadm_svr_stat_body svr[1];
};


/* WSADM_CLIINFO return structures */
struct wsadm_cliinfo_body {
	int	no;	/* cli index */
	int	clid;	/* CLID */
	int	hthno;
	int	count;	
	int	idle;
	int	vhostno;
	int	local_port;
	int	sprno;
	char	status[WEBTOB_NAME_SIZE];
	char	remote_ipaddr[WEBTOB_NAME_SIZE];
	char	usrname[WEBTOB_NAME_SIZE];
	char	local_ipaddr[WEBTOB_NAME_SIZE];
};

struct wsadm_cliinfo {
	/* fixed header */
	struct wsadm_header header;
	/* variable length body */
	struct wsadm_cliinfo_body cli[1];
};


/* WSADM_BOOT return structures */
struct wsadm_boot_body {
	int	count;
	int	opt_int[3];
	char	name1[WEBTOB_NAME_SIZE];
	char	name2[WEBTOB_NAME_SIZE];
	char	clopt[WEBTOB_CLOPT_LENGTH];
};

struct wsadm_boot {
	/* fixed header */
	struct wsadm_header header;
	/* fixed body */
	struct wsadm_boot_body args;
};


/* WSADM_DOWN return structures */
struct wsadm_down_body {
	int	count;
	int	opt_int[3];
	char	name1[WEBTOB_NAME_SIZE];
	char	name2[WEBTOB_NAME_SIZE];
};

struct wsadm_down {
	/* fixed header */
	struct wsadm_header header;
	/* fixed body */
	struct wsadm_down_body args;
};


#if defined (__cplusplus)
extern "C" {
#endif

int __cdecl wsadmin_init(char *cfile);
int __cdecl wsadmin_done();
/*
   wsadmin(WSADM_DISCON, int *clid, WSADM_FFLAG, TPNOFLAGS);
   wsadmin(WSADM_NODE_INFO, struct wsadm_node_info *info, TPNOFLAGS, TPNOFLAGS);
 */
int __cdecl wsadmin(int cmd, void *arg, int opt, long flags);

#if defined (__cplusplus)
}
#endif

#endif       /* end of _WEBTOB_WSADMIN_H  */
