# $OpenBSD: Makefile,v 1.10 2019/07/12 20:43:59 sthen Exp $

VERSION=	11.9

SHARED_LIBS=	ecpg		7.9 \
		ecpg_compat	4.9 \
		pgtypes		4.8 \
		pq		6.10

pre-build:
	${PRE_BUILD}

post-build:
	${POST_BUILD}

post-install:
	${POST_INSTALL}

.include <bsd.port.mk>
