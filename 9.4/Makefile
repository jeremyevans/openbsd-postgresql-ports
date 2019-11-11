# $OpenBSD: Makefile,v 1.3 2017/06/13 12:31:44 schwarze Exp $

VERSION=	9.4.24

SHARED_LIBS=	ecpg		7.6 \
		ecpg_compat	4.6 \
		pgtypes		4.5 \
		pq		6.7

pre-build:
	${PRE_BUILD}

post-build:
	${POST_BUILD}

post-install:
	${POST_INSTALL}

.include <bsd.port.mk>
