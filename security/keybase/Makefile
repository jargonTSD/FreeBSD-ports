PORTNAME=	keybase
PORTVERSION=	6.0.4
PORTREVISION=	2
DISTVERSIONPREFIX=	v
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/go/:gomod
#MASTER_SITES=	https://raw.githubusercontent.com/keybase/client/v${PORTVERSION}/go/:gomod
CATEGORIES=	security
DISTFILES=	go.mod:gomod


MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Keybase.io client and Keybase Filesystem (KBFS)
WWW=		https://keybase.io/docs/command_line

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		cpe go:modules tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	keybase
GH_PROJECT=	client

GO_MODULE=	github.com/keybase/client/go
GO_TARGET=	./keybase ./kbfs/kbfsfuse ./kbfs/kbfsgit/git-remote-keybase ./kbfs/kbfstool
GO_BUILDFLAGS=	-tags production
WRKSRC_SUBDIR=	go

PLIST_FILES=	bin/git-remote-keybase bin/kbfsfuse bin/kbfstool bin/keybase

.include <bsd.port.mk>
