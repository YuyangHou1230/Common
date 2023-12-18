TEMPLATE = subdirs

SUBDIRS += \
    Controls \
    Examples \
    Helper \
    Utility

Examples.depends = Controls Helper Utility
