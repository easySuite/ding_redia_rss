ding_redia_rss
==============

Drupal module for the Ding project which exposes news and events through RSS feeds with Redia specific fields for the BApps project

##Requirements:
- flag
- views_rss - needed for customization of RSS feed with Views module support.
- views_rss_media - allows to add paths to media elements in feed provided by Views RSS module.

##Installation:
Enable ding_redia_rss module on @/admin/modules page. The required modules will be enable automatically, be sure that those module are present in build.

##Configuration:
This module don't require any specific configuration. All field mappings are done in views and exported as feature.

##Usage:
Ding Redia RSS module provide 4 paths on which is outputted resulting feeds for news and events:
* @/ding-redia-rss/event
* @/ding-redia-rss/event/app
* @/ding-redia-rss/news
* @/ding-redia-rss/news/app
