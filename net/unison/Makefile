PORTNAME=	unison
PORTVERSION=	2.53.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	User-level file synchronization tool
WWW=		https://www.cis.upenn.edu/~bcpierce/unison/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}

nox11_PKGNAMESUFFIX=		-nox11
nox11_CONFLICTS_INSTALL=	unison

x11_CONFLICTS_INSTALL=	unison-nox11
x11_BUILD_DEPENDS=	icotool:graphics/icoutils \
			ocaml-lablgtk3>0:x11-toolkits/ocaml-lablgtk3
x11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz

USES=		gmake localbase
USE_OCAML=	yes
WRKSRC_SUBDIR=	src
NO_OCAML_RUNDEPENDS=	yes
CONFLICTS=	unison-devel
MAKE_ENV=	CLIBS="${LIBS:S/^-/-ccopt -/}" \
		COFLAGS="${CFLAGS:C/ *(-[^ ]*) */ -ccopt \"\1 \"/gW}"
ALL_TARGET=	unison all
PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	bcpierce00

DOCS=		NEWS.md README.md

OPTIONS_DEFINE=		DOCS FSMONITOR
OPTIONS_DEFAULT?=	FSMONITOR

FSMONITOR_DESC=	Compile and install fsmonitor plugin

OPTIONS_SUB=	YES

FSMONITOR_LIB_DEPENDS=	libinotify.so:devel/libinotify

.if ${FLAVOR} == nox11
MAKE_ARGS=	UISTYLE=text
PKGMESSAGE=	${PKGDIR}/pkg-message.nox11
PLIST_SUB+=	X11="@comment "
.else
MAKE_ARGS=	UISTYLE=gtk3
SUB_FILES=	${PORTNAME}.desktop
USE_GNOME+=	atk cairo gdkpixbuf2 glib20 gtk30 pango
USES+=		gettext-runtime gnome
PLIST_SUB+=	X11=""
.endif

post-patch-FSMONITOR-off:
	@${REINPLACE_CMD} -e 's/-include fsmonitor/#&/' \
		${WRKSRC}/Makefile.OCaml

post-patch:
.if ${FLAVOR} == x11
	@${REINPLACE_CMD} -Ee 's@(\+|/)(lablgtk3)@\1site-lib/\2@' \
		${WRKSRC}/Makefile.OCaml
.endif

post-build:
	(cd ${WRKSRC} && HOME=${WRKSRC} ./unison -selftest -ui text -batch)
.if ${FLAVOR} == x11
	@${ECHO} Building text-only version
	@${ECHO} ${WRKSRC}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} UISTYLE=text NAME=unison-text
	@cd ${WRKSRC}/win32rc && ${LOCALBASE}/bin/icotool -x U.ico
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.if ${FLAVOR} == x11
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-text ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/win32rc/U_4_48x48x32.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
.endif

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/.. && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

do-install-FSMONITOR-on:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-fsmonitor ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
