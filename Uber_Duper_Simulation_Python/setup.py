from distutils.core import setup
from Cython.Build import cythonize

setup(
  name = 'Uber Duper Simulation',
  ext_modules = cythonize("main_2_2_7.pyx"),
)