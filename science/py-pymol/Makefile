PORTNAME=	pymol
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0-97
DISTVERSIONSUFFIX=	-gd24468af
CATEGORIES=	science biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenGL-based molecular visualization system
WWW=		https://pymol.org/2/

LICENSE=	PyMOL
LICENSE_NAME=	Open-Source PyMOL Copyright
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYNUMPY} \
		${LOCALBASE}/include/glm/glm.hpp:math/glm \
		${LOCALBASE}/include/mmtf.hpp:science/mmtf-cpp
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libmsgpackc.so:devel/msgpack-c \
		libnetcdf.so:science/netcdf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Pmw>0:x11-toolkits/py-Pmw@${PY_FLAVOR} \
		${PYNUMPY}

USES=		compiler:c++11-lang gl gnome python:3.5+ tar:bz2
USE_GL=		gl glew glu glut
USE_GNOME=	libxml2
USE_PYTHON=	distutils concurrent # autoplist is broken: https://github.com/schrodinger/pymol-open-source/issues/99

USE_GITHUB=	yes
GH_ACCOUNT=	schrodinger
GH_PROJECT=	${PORTNAME}-open-source

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}chempy # chempy port is unrelated, see https://github.com/schrodinger/pymol-open-source/issues/100

CXXFLAGS+=	-DMSGPACK_NO_BOOST # in line with MSGPACK_USE_BOOST=OFF in devel/msgpack-cxx

OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	QT5 TK
OPTIONS_DEFAULT=	QT5

QT5_USES=		pyqt:5
QT5_USE=		PYQT=pyqt5:run

post-patch-TK-on:
	@${REINPLACE_CMD} -e ' \
		23s|if not PYQT_NAME:|if False:| ; \
		s|from PyQt5 import|from X import|' \
		${WRKSRC}/modules/${PORTNAME}/Qt/__init__.py

post-install:
	@${REINPLACE_CMD} -i '' -e 's|#!/bin/bash|#!/bin/sh|' ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/_cmd*.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/chempy/champ/_champ*.so

.include <bsd.port.mk>
