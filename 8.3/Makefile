VERSION=	8.3.23
REVISION=	1

SHARED_LIBS=	ecpg		7.0 \
		ecpg_compat	4.0 \
		pgtypes		3.0 \
		pq		6.1

EXTRA_CONFIGURE_ARGS =	--without-openssl

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
