PORTNAME=	pycsw
PORTVERSION=	2.6.1
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OGC CSW server implementation
WWW=		https://pycsw.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}geolinks>=0:science/py-geolinks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}OWSLib>=0:graphics/py-OWSLib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>=0:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Shapely>=0:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0:devel/py-xmltodict@${PY_FLAVOR}

USES=		cpe python:3.8+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
