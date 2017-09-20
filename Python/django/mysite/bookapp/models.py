# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models

# Create your models here.

class BetterCharField(models.Field):
    def db_type(self,connection):
        return 'char(25)'
# class MyModel(models.Model):
#     my_field = BetterCharField()
class BookQuerySet(models.QuerySet):
    def little(self):
        return self.filter(id__lt = 4)
class BookManager(models.Manager):
    def get_queryset(self):
        return BookQuerySet(self.model,using = self.db )
    def title_count(self,keywords):
        return self.filter(title_icontain = keywords).count()


class Publisher(models.Model):
    name = models.CharField(max_length = 30)
    address = models.CharField(max_length = 50)
    city = models.CharField(max_length = 60)
    state_province = models.CharField(max_length = 30)
    country = models.CharField(max_length = 50)
    website = models.URLField(verbose_name = '网址')

# 字段名:
    def __unicode__(self):
        return '%s '%(self.name)


    class Meta:
        # 数据库中表的名字
        db_table = 'publisher'
        #表名
        verbose_name = '出版社'
        # 去掉s
        verbose_name_plural = verbose_name
        ordering = ['name']

class Author(models.Model):
    first_name = models.CharField(max_length = 30)
    last_name = models.CharField(max_length = 30)
    email = models.EmailField(blank = True,verbose_name = 'email')


class Book(models.Model):
    title = models.CharField(max_length = 100)
    publication_date = models.DateField(blank = True,null = True)
    price = models.FloatField(default = 0.0)
    publisher = models.ForeignKey(Publisher,related_name = 'books')
    author = models.ManyToManyField(Author)
    objects = BookManager()
