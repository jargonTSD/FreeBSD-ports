PORTNAME=	xstatic-jquery-migrate
PORTVERSION=	3.3.2.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-JQuery-Migrate-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JQuery-Migrate (XStatic packaging standard)
WWW=		https://github.com/jquery/jquery-migrate

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xstatic>=0:devel/py-xstatic@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
