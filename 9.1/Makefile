VERSION=	9.1.24
REVISION=	1

SHARED_LIBS=	ecpg		7.3 \
		ecpg_compat	4.3 \
		pgtypes		4.2 \
		pq		6.4

EXTRA_CONFIGURE_ARGS = --without-openssl

pre-build:
	${PRE_BUILD}

post-build:
	${POST_BUILD}

post-install:
	${POST_INSTALL}

.include <bsd.port.mk>
