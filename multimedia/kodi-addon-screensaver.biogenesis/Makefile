PORTNAME=	screensaver.biogenesis
PORTVERSION=	20.1.0
DISTVERSIONSUFFIX=	-Nexus
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	BioGenesis screensaver for Kodi
WWW=		https://github.com/xbmc/screensaver.biogenesis

LICENSE=	GPLv2+

USES=		cmake gl kodi
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
USE_GL=		egl gl glu

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
