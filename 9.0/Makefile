VERSION=	9.0.23
REVISION=	1

SHARED_LIBS=	ecpg		7.2 \
		ecpg_compat	4.2 \
		pgtypes		4.1 \
		pq		6.3

EXTRA_CONFIGURE_ARGS = --without-openssl

pre-build:
	${PRE_BUILD}

post-build:
	${POST_BUILD}

post-install:
	${POST_INSTALL}

.include <bsd.port.mk>
