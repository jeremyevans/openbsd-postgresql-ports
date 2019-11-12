# $OpenBSD: Makefile,v 1.3 2017/06/13 12:31:44 schwarze Exp $

VERSION=	9.1.24

SHARED_LIBS=	ecpg		7.3 \
		ecpg_compat	4.3 \
		pgtypes		4.2 \
		pq		6.4

pre-build:
	${PRE_BUILD}

post-build:
	${POST_BUILD}

post-install:
	${POST_INSTALL}

.include <bsd.port.mk>
