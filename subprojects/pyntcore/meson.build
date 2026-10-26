project('pyntcore', ['cpp'],
        default_options: ['warning_level=1', 'cpp_std=c++23',
                          'b_colorout=auto', 'optimization=2', 'b_pie=true'])

# GCC reports a false positive in wpi::util::StructArrayBuffer (via an inlined
# std::vector constructor) that isn't suppressed even though it's in a system
# header. Seen with the aarch64 GCC 14 cross compiler.
if meson.get_compiler('cpp').get_id() == 'gcc'
    add_project_arguments('-Wno-alloc-size-larger-than', language: 'cpp')
endif

subdir('semiwrap')

ntcore_sources += files(
    'ntcore/src/ntcore.cpp',
    'ntcore/src/nt_instance.cpp',
    'ntcore/src/py2value.cpp',
    'ntcore/src/pyentry.cpp',
)

subdir('semiwrap/modules')
