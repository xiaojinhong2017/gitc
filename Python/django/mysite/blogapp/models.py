# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models

# Create your models here.
class Blog(models.Model):
    title = models.CharField(max_length = 50 )
    tag = models.CharField(max_length = 50)
    content = models.TextField()
    time = models.DateTimeField(blank = True)
    see = models.IntegerField(null = True)
class Comment(models.Model):
    comment = models.CharField(max_length = 1000)
    blog = models.ForeignKey(Blog)
