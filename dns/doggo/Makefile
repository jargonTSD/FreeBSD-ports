PORTNAME=	doggo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.5
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern command-line DNS client (like dig)
WWW=		https://github.com/mr-karan/doggo

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.19,modules

GO_MODULE=	github.com/mr-karan/doggo
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/fish/completions/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

post-install:
	# install completions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
