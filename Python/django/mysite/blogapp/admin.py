# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.contrib import admin

# Register your models here.
from blogapp.models import *
admin.site.register(Comment)
admin.site.register(Blog)
