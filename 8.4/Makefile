VERSION=	8.4.22
REVISION=	0

SHARED_LIBS=	ecpg		7.1 \
		ecpg_compat	4.1 \
		pgtypes		4.0 \
		pq		6.2

pre-build:
	${PRE_BUILD}

post-build:
	${POST_BUILD}

post-install:
	${POST_INSTALL}
	rm ${PREFIX}/man/man{1,7}/*
	rm -rf ${PREFIX}/share/doc/${POSTGRESQL_DIR}/html

.include <bsd.port.mk>
