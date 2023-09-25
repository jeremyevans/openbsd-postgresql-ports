COMMENT ?=	PostgreSQL RDBMS old version

DISTNAME ?=	postgresql-${VERSION}
PKGNAME ?=	postgresql-old-${VERSION}

CATEGORIES ?=	databases

HOMEPAGE ?=	http://www.postgresql.org/

# BSD
PERMIT_PACKAGE ?=	Yes

WANTLIB ?= c crypto curses m perl readline ssl xml2 z

SITES ?=	https://ftp.postgresql.org/pub/source/v${VERSION}/ \
		ftp://ftp.postgresql.org/pub/source/v${VERSION}/

MAKE_FILE ?=	GNUmakefile

SUBST_VARS =	VERSION MAJOR_VERSION RC_VERSION DATA_DIR POSTGRESQL_DIR

USE_GMAKE ?=	Yes

CONFIGURE_STYLE ?=	gnu

MODULES ?=	lang/python
MODPY_RUNDEP ?=	No
MAJOR_VERSION ?=	${VERSION:C/.[0-9]+$//}
RC_VERSION ?=		${MAJOR_VERSION:S/.//}
POSTGRESQL_DIR ?=	postgresql-${MAJOR_VERSION}
DATA_DIR ?=		/var/postgresql/data-${MAJOR_VERSION}

CONFIGURE_ENV ?=ac_cv_path_PYTHON=${MODPY_BIN} \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS ?=	--with-openssl=/usr \
			--with-perl \
			--without-python \
			--with-pam=no \
			--with-uuid=bsd \
			--enable-integer-datetimes \
			--bindir="${PREFIX}/bin/${POSTGRESQL_DIR}" \
			--libdir="${PREFIX}/lib/${POSTGRESQL_DIR}" \
			--includedir="${PREFIX}/include/${POSTGRESQL_DIR}" \
			--datadir="${PREFIX}/share/${POSTGRESQL_DIR}" \
			--with-includes="${INCLUDES}" \
			--with-libraries="${LOCALBASE}/lib/" \
			--with-system-tzdata="/usr/share/zoneinfo" \
			--with-openssl \
			--with-libxml \
			--disable-thread-safety

MODGNU_CONFIG_GUESS_DIRS ?=	${WRKSRC}/config

ALL_TARGET ?=	all
INSTALL_TARGET ?=	install

LIB_DEPENDS ?= textproc/libxml

MAKE_ENV ?=	LIBpq_MAJOR=${LIBpq_VERSION:R} \
		LIBpq_MINOR=${LIBpq_VERSION:E} \
		LIBecpg_MAJOR=${LIBecpg_VERSION:R} \
		LIBecpg_MINOR=${LIBecpg_VERSION:E} \
		LIBecpg_compat_MAJOR=${LIBecpg_compat_VERSION:R} \
		LIBecpg_compat_MINOR=${LIBecpg_compat_VERSION:E} \
		LIBpgtypes_MAJOR=${LIBpgtypes_VERSION:R} \
		LIBpgtypes_MINOR=${LIBpgtypes_VERSION:E}

# Work around Makefile issue where it attempts to rebuild
# the documentation even if it is not necessary.
PRE_BUILD ?= touch ${WRKSRC}/doc/src/sgml/*-stamp

POST_BUILD ?= cd ${WRKSRC}/contrib && gmake

INSTALL_REPLACE = 's/^install_bin = .*$$/ifdef BSD_INSTALL_SCRIPT\ninstall_bin
INSTALL_REPLACE += = \$$\(subst -m 755,,\$${BSD_INSTALL_SCRIPT}\)
INSTALL_REPLACE += \nelse\ninstall_bin = \/usr\/bin\/install -c -o ${BINOWN}
INSTALL_REPLACE += -g ${BINGRP}\nendif/'

POST_INSTALL ?= (cd ${WRKSRC}/contrib && gmake install) && \
		perl -i -pe ${INSTALL_REPLACE} \
			${PREFIX}/lib/${POSTGRESQL_DIR}/pgxs/src/Makefile.global && \
		mv ${PREFIX}/share/doc/{postgresql,${POSTGRESQL_DIR}}
