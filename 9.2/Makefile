# $OpenBSD: Makefile,v 1.3 2017/06/13 12:31:44 schwarze Exp $

VERSION=	9.2.24

SHARED_LIBS=	ecpg		7.4 \
		ecpg_compat	4.4 \
		pgtypes		4.3 \
		pq		6.5

pre-build:
	${PRE_BUILD}

post-build:
	${POST_BUILD}

post-install:
	${POST_INSTALL}

.include <bsd.port.mk>
