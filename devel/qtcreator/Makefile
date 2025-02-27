PORTNAME=	qtcreator
DISTVERSION=	9.0.2
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/qtcreator/${DISTVERSION:R}/${DISTVERSION}
DISTNAME=	qt-creator-opensource-src-${DISTVERSION}
DIST_SUBDIR=	KDE/Qt/qtcreator

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++ and QML IDE for Qt development
WWW=		https://qt-project.org/wiki/Category:Tools::QtCreator

LICENSE=	QtGPL
LICENSE_GROUPS_QtGPL=	GPL
LICENSE_NAME=	GPLv3 with Qt Company GPL Exception 1.0
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL3-EXCEPT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader \
		libxkbcommon.so:x11/libxkbcommon \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang desktop-file-utils gl llvm:build,run,min=15 \
		pkgconfig python qt:6 shebangfix tar:xz
USE_GL=		gl
USE_LDCONFIG=	${LOCALBASE}/lib/${PORTNAME}
USE_QT=		5compat base declarative positioning quick3d quicktimeline \
		serialport shadertools svg tools translations webchannel

SHEBANG_FILES=	bin/qtcreator.sh \
		doc/fixnavi.pl \
		doc/qtcreatordev/examples/aggregation/test.sh \
		scripts/*.pl \
		scripts/*.py \
		scripts/*.sh \
		share/qtcreator/scripts/openTerminal.py \
		share/qtcreator/translations/check-ts.pl \
		share/qtcreator/translations/*.py \
		src/app/winicons/createicons.sh \
		src/libs/glsl/make-parser.sh \
		src/libs/qmljs/parser/changeLicense.py \
		src/libs/qmljs/parser/gen-parser.sh \
		src/libs/qt-breakpad/qtbreakpadsymbols \
		src/plugins/perfprofiler/tracepoints.sh \
		src/tools/icons/*.sh \
		src/tools/icons/*.py \
		tests/system/tools/findUnusedObjects.py \
		tests/system/tools/objectsToTable.py

# Provide library paths, default llvm first as a hint to the clang code model.
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH:STRING="${LLVM_PREFIX};${PREFIX}"
# - Prevent accidental pickup of devel/elfutils libraries.
# - Prevent accidental use of devel/googletest headers, use bundled.
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_elfutils \
		CMAKE_DISABLE_FIND_PACKAGE_Googletest
# - Disable precompiled headers for now, they are missing compile flags.
# - Suppress installed yaml-cpp, use bundled.
CMAKE_OFF=	BUILD_WITH_PCH \
		yaml-cpp_FOUND

LDFLAGS+=	-lexecinfo

# be paranoid and do not extract qbs (devel/qbs) copy from source tree
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/src/shared/qbs'

PLIST_SUB=		SHLIB_VER="${PORTVERSION}"
PORTDOCS=		*

OPTIONS_DEFINE=		DOCS EXAMPLES QTWEBENGINE
OPTIONS_DEFAULT=	DOCS EXAMPLES
OPTIONS_DEFAULT_amd64=	QTWEBENGINE
OPTIONS_DEFAULT_i386=	QTWEBENGINE
OPTIONS_SUB=		yes

DOCS_DESC=		Install the Qt6 api documentation
EXAMPLES_DESC=		Install the Qt6 example projects
QTWEBENGINE_DESC=	Add dependency on qt6-webengine

DOCS_USE=		QT=doc:run
DOCS_CMAKE_BOOL=	WITH_DOCS

EXAMPLES_USE=		QT=examples:run

QTWEBENGINE_USE=	qt=webengine
QTWEBENGINE_CMAKE_BOOL=	BUILD_HELPVIEWERBACKEND_QTWEBENGINE

# Documentation is excluded from the default build targets.
do-build-DOCS-on:
	${CMAKE_BIN} --build ${BUILD_WRKSRC} --target docs

# This also means separate install steps for documentation.
do-install-DOCS-on:
	${CMAKE_BIN} --install ${BUILD_WRKSRC} --prefix ${STAGEDIR}${PREFIX} \
	    --component qch_docs
	${CMAKE_BIN} --install ${BUILD_WRKSRC} --prefix ${STAGEDIR}${PREFIX} \
	    --component html_docs

.include <bsd.port.mk>
