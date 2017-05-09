include_defs('//BUCKAROO_DEPS')

cxx_binary(
  name = 'error-bench',
  header_namespace = 'error-bench',
  srcs = glob([
    'error-bench/src/**/*.cpp',
  ]),
  headers = subdir_glob([
    ('error-bench/include', '**/*.hpp'),
    ('error-bench/include', '**/*.h'),
  ]),
  deps = BUCKAROO_DEPS,
)

