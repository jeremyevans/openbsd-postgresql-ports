# $OpenBSD: Makefile,v 1.3 2017/06/13 12:31:44 schwarze Exp $

VERSION=	9.3.25

SHARED_LIBS=	ecpg		7.5 \
		ecpg_compat	4.5 \
		pgtypes		4.4 \
		pq		6.6

pre-build:
	${PRE_BUILD}

post-build:
	${POST_BUILD}

post-install:
	${POST_INSTALL}

.include <bsd.port.mk>
