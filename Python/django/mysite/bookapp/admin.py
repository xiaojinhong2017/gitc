# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.contrib import admin

from bookapp.models import *
# Register your models here.
class AuthorAdmin(admin.ModelAdmin):
    list_display = ('first_name','last_name','email')
    search_fields = ('first_name','last_name')

# 添加第三方插件
    class Media:
        js = (
             '/static/js/a.js',
        )
# 后台美化工具 sudo pip install django-grappelli

class BookAdmin(admin.ModelAdmin):
    #日期筛选
    list_filter = ('publication_date',)
    #置顶日期
    date_hierarchy = 'publication_date'
    #排序若与model中冲突以此为准
    ordering = ('-publication_date',)
    #在具体项中以什么顺序显示,显示哪几项
    # fields = ('title','author','publisher')


class PublisherAdmin(admin.ModelAdmin):
    fieldsets = (
     ('基本信息',{'fields':('name','address','city','state_province','country')}),
     ('高级设置',{'classes':('collapse',),
                 'fields':('website',)
                 })
    )
    list_display = ('name','website')

    # 两个只能用一个
    # list_display_links = ('name','website')
    list_editable = ('website','website')

admin.site.register(Publisher,PublisherAdmin)
admin.site.register(Author,AuthorAdmin)
admin.site.register(Book,BookAdmin)
