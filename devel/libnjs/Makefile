PORTNAME=	libnjs
DISTVERSION=	0.7.11
CATEGORIES=	devel www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	NGINX JavaScript static library
WWW=		https://nginx.org/en/docs/njs/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe ssl

CPE_VENDOR=	f5

USE_GITHUB=	yes
GH_TUPLE=	nginx:njs:${DISTVERSION}
HAS_CONFIGURE=	yes

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

PLIST_FILES=	include/njs_addr2line.h \
		include/njs_arr.h \
		include/njs_array_buffer.h \
		include/njs_array.h \
		include/njs_assert.h \
		include/njs_async.h \
		include/njs_auto_config.h \
		include/njs_boolean.h \
		include/njs_buffer.h \
		include/njs_chb.h \
		include/njs_clang.h \
		include/njs_date.h \
		include/njs_diyfp.h \
		include/njs_djb_hash.h \
		include/njs_dtoa_fixed.h \
		include/njs_dtoa.h \
		include/njs_encoding.h \
		include/njs_error.h \
		include/njs_event.h \
		include/njs_file.h \
		include/njs_function.h \
		include/njs_generator.h \
		include/njs_iterator.h \
		include/njs_json.h \
		include/njs_lexer_tables.h \
		include/njs_lexer.h \
		include/njs_lvlhsh.h \
		include/njs_main.h \
		include/njs_malloc.h \
		include/njs_math.h \
		include/njs_md5.h \
		include/njs_module.h \
		include/njs_mp.h \
		include/njs_murmur_hash.h \
		include/njs_number.h \
		include/njs_object_hash.h \
		include/njs_object_prop_declare.h \
		include/njs_object.h \
		include/njs_parser.h \
		include/njs_promise.h \
		include/njs_queue.h \
		include/njs_random.h \
		include/njs_rbtree.h \
		include/njs_regex.h \
		include/njs_regexp_pattern.h \
		include/njs_regexp.h \
		include/njs_scope.h \
		include/njs_sha1.h \
		include/njs_sha2.h \
		include/njs_sprintf.h \
		include/njs_str.h \
		include/njs_string.h \
		include/njs_strtod.h \
		include/njs_symbol.h \
		include/njs_time.h \
		include/njs_timer.h \
		include/njs_trace.h \
		include/njs_typed_array.h \
		include/njs_types.h \
		include/njs_unicode_lower_case.h \
		include/njs_unicode_upper_case.h \
		include/njs_unicode.h \
		include/njs_unix.h \
		include/njs_utf16.h \
		include/njs_utf8.h \
		include/njs_utils.h \
		include/njs_value_conversion.h \
		include/njs_value.h \
		include/njs_variable.h \
		include/njs_vm.h \
		include/njs_vmcode.h \
		include/njs.h \
		lib/libnjs.a

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} build/libnjs.a

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/build/njs_auto_config.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/build/libnjs.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
