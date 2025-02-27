PORTNAME=	mantis
PORTVERSION=	2.25.6
PORTEPOCH=	1
CATEGORIES=	databases www
MASTER_SITES=	SF/mantisbt/mantis-stable/${PORTVERSION}
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	mantisbt-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	zab@zltech.eu
COMMENT=	Bug tracking system written in PHP
WWW=		https://www.mantisbt.org/

LICENSE=	GPLv2

USES=		php:flavors
USE_GITHUB=	nodefault
USE_PHP=	fileinfo filter hash json mbstring pcre session xml

DATADIR=	${WWWDIR}
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
PLIST_FILES=	${WWWDIR}/.imgbotconfig
PORTDATA=	*

OPTIONS_DEFAULT=	${OPTIONS_GROUP_PLUGINS} MYSQL
OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	ACTIVITY ANNOUNCE COLORIZED CUSTOMREPORTER EMAILREP \
			EVENTLOG FLTBUGLST GAUGE JQUERYCHOSEN JQUERYUI LIGHTBOX \
			PIWIK SAMPLEAUTH SI SLACK SNIPPETS TASKODROME \
			TIMETRACKING
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL
OPTIONS_SUB=		yes

ACTIVITY_DESC=		Shows bug notes by creation date
ANNOUNCE_DESC=		Announcements
COLORIZED_DESC=		Colorized Theme
CUSTOMREPORTER_DESC=	Allow the selection of a Reporter from a list
EMAILREP_DESC=		Allow to report an issue by sending an email
EVENTLOG_DESC=		Allow MantisBT components to log data
FLTBUGLST_DESC=		Allow to filter by a set of bug IDs
GAUGE_DESC=		Voting for tickets
JQUERYCHOSEN_DESC=	Support the Library Chosen to MantisBT
JQUERYUI_DESC=		jQuery UI library + Combobox
LIGHTBOX_DESC=		Plugin to open attachments using Lightbox
PIWIK_DESC=		Paste print screens directly
SAMPLEAUTH_DESC=	A sample authentication plugin
SI_DESC=		Source control integration
SLACK_DESC=		Slack integration
SNIPPETS_DESC=		Text snippets that can be pasted into text fields
TASKODROME_DESC=	Interactive scrum board
TIMETRACKING_DESC=	Time Tracking

ACTIVITY_GH_TUPLE=		mantisbt-plugins:Activity:2b1e3da2243613ebd13878501cfdcd9422cf4d4b:activity/plugins/Activity
ANNOUNCE_GH_TUPLE=		mantisbt-plugins:Announce:v2.4.3:announce/plugins/Announce
COLORIZED_GH_TUPLE=		mantisbt-plugins:MantisBT-Colorized:f43dc4cc36e8851f8df1797116f904ccf5f1689d:colorized/css/themes/colorized
CUSTOMREPORTER_GH_TUPLE=	mantisbt-plugins:CustomReporter:v2.0.0:customreporter/plugins/CustomReporter
EMAILREP_GH_TUPLE=		mantisbt-plugins:EmailReporting:EmailReporting_0.10.1:emailrep/plugins/EmailReporting
EVENTLOG_GH_TUPLE=		mantisbt-plugins:EventLog:74fd03cf85a32088a0206bc73bb14ddbd148aed2:eventlog/plugins/EventLog
FLTBUGLST_GH_TUPLE=		mantisbt-plugins:FilterBugList:v2.1.0:fltbuglist/plugins/FilterBugList
GAUGE_GH_TUPLE=			mantisbt-plugins:GaugeSupport:9bd7e7dd1f496d28ee7ad2d831db3a276f996054:gauge/plugins/GaugeSupport
JQUERYCHOSEN_GH_TUPLE=		mantisbt-plugins:JqueryChosen:dc305e987ea3693bb92d22545ba23f3fc44d04c3:jquerychosen
JQUERYUI_GH_TUPLE=		mantisbt-plugins:jQuery-UI:ca77afa51166658b469dd11bfff7713485935bda:jqueryui
LIGHTBOX_GH_TUPLE=		mantisbt-plugins:Lightbox:f8220ba689378054ca433f718d909dc41a803def:lightbox/plugins/Lightbox
MYSQL_USE=			PHP=mysqli
PGSQL_USE=			PHP=pgsql
PIWIK_GH_TUPLE=			mantisbt-plugins:piwik:a2dba46836bdc07a80b8040e889ba0606f97415e:piwik
SAMPLEAUTH_GH_TUPLE=		mantisbt-plugins:SampleAuth:34856715f49a5c273f33e094c759c0e0b52b3912:sampleauth/plugins/SampleAuth
SI_USE=				PHP=curl
SI_GH_TUPLE=			mantisbt-plugins:source-integration:v2.6.0:si
SLACK_GH_TUPLE=			mantisbt-plugins:Slack:v1.0.3:slack
SNIPPETS_GH_TUPLE=		mantisbt-plugins:Snippets:v2.4.1:snippets/plugins/Snippets
TASKODROME_GH_TUPLE=		mantisbt-plugins:Taskodrome:69577a62e7db1c50945b513616ca15db97eeb67f:taskodrome
TIMETRACKING_GH_TUPLE=		mantisbt-plugins:timetracking:3a560673d85e17651fc1994f5e09e2ae9df62336:timetracking

post-extract-COLORIZED-on:
	@${MV} ${WRKSRC_colorized}/colorized.css ${WRKSRC_colorized}/default.css
	@${CP} ${WRKSRC_colorized}/assets/screenshot-1.png ${WRKSRC_colorized}/colorized.png

post-extract-JQUERYCHOSEN-on:
	@${MV} ${WRKSRC_jquerychosen}/JqueryChosen ${WRKSRC}/plugins/

post-extract-JQUERYUI-on:
	@${MV} ${WRKSRC_jqueryui}/jQueryUI ${WRKSRC}/plugins/

post-extract-PIWIK-on:
	@${MV} ${WRKSRC_piwik}/Piwik ${WRKSRC}/plugins/

post-extract-SI-on:
	@${MV} ${WRKSRC_si}/Source* ${WRKSRC}/plugins

post-extract-TASKODROME-on:
	@${MV} ${WRKSRC_taskodrome}/Taskodrome ${WRKSRC}/plugins/

post-extract-TIMETRACKING-on:
	@${MV} ${WRKSRC_timetracking}/TimeTracking ${WRKSRC}/plugins/

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
