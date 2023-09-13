# setup.py
from distutils.core import setup, Extension

setup(name='sample',
      ext_modules=[
        Extension('spam',
                  ['spammodule.c'],
                  library_dirs = ['/usr/local/lib'],
                  )
        ]
)

setup(name='sample2',
      ext_modules=[
        Extension('custom',
                  ['custom.c'],
                  library_dirs = ['/usr/local/lib'],
                  )
        ]
)