import os

THIS_DIR = os.path.dirname(os.path.realpath(__file__))

def FlagsForFile( filename, **kwargs ):
    return { 'flags' : ['-x', 'c++', '-std=c++11',
                        '-I', os.path.join(THIS_DIR, 'inc'),
                        '-I', os.path.join(THIS_DIR, 'thirdparty')
                       ]
           , 'do_cache': True
           }

