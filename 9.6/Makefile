# $OpenBSD: Makefile,v 1.6 2018/09/06 19:10:53 tb Exp $

VERSION=	9.6.6
REVISION=	4

SHARED_LIBS=	ecpg		7.8 \
		ecpg_compat	4.8 \
		pgtypes		4.7 \
		pq		6.9 

pre-build:
	${PRE_BUILD}

post-build:
	${POST_BUILD}

post-install:
	${POST_INSTALL}

.include <bsd.port.mk>
