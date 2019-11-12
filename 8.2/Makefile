# $OpenBSD: Makefile,v 1.3 2017/06/13 12:31:44 schwarze Exp $

VERSION=	8.2.23

SHARED_LIBS=	ecpg		6.0 \
		ecpg_compat	3.0 \
		pgtypes		2.0 \
		pq		6.0

pre-build:
	${PRE_BUILD}

post-build:
	${POST_BUILD}

post-install:
	mkdir ${PREFIX}/share/doc/postgresql
	${POST_INSTALL}
	rm ${PREFIX}/man/man{1,7}/*
	rm -rf ${PREFIX}/share/doc/${POSTGRESQL_DIR}/html
	rm -r ${PREFIX}/doc

.include <bsd.port.mk>
