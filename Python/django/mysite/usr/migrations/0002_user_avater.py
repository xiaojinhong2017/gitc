# -*- coding: utf-8 -*-
# Generated by Django 1.11.4 on 2017-09-14 09:02
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('usr', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='user',
            name='avater',
            field=models.ImageField(blank=True, max_length=200, upload_to=b'', verbose_name='Head_portrait'),
        ),
    ]
