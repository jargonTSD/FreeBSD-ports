PORTNAME=	gspell
PORTVERSION=	1.10.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Spell checking for GTK+
WWW=		https://wiki.gnome.org/Projects/gspell

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libfribidi.so:converters/fribidi \
		libicudata.so:devel/icu

PORTSCOUT=	limitw:even

USES=		gmake gnome iconv libtool pathfix pkgconfig tar:xz vala:build
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 introspection:build \
		libxml2 pango
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-tools
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

.include <bsd.port.mk>
