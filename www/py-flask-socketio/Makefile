PORTNAME=	flask-socketio
PORTVERSION=	5.3.3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Flask-SocketIO-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Socket.IO integration for Flask applications
WWW=		https://github.com/miguelgrinberg/Flask-SocketIO

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.9:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-socketio>=5.0.2:devel/py-python-socketio@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
