from setuptools import find_packages
from setuptools import setup

setup(
    name='my_beginner_tutorials',
    version='0.0.0',
    packages=find_packages(
        include=('my_beginner_tutorials', 'my_beginner_tutorials.*')),
)
