core = 7.x
api = 2

; Projects
projects[flag][subdir] = "contrib"
projects[flag][version] = "2.0"

projects[views_rss][subdir] = "contrib"
projects[views_rss][version] = "2.0-rc4"

; This specific checkout is only because of the module is dev branch only.
projects[views_rss_media][type] = "module"
projects[views_rss_media][subdir] = "contrib"
projects[views_rss_media][download][type] = "git"
projects[views_rss_media][download][url] = "http://git.drupal.org/project/views_rss_media.git"
projects[views_rss_media][download][revision] = "14f7cc90d41c0186d2356ff528ac316a16eba3fd"
projects[views_rss_media][patch][] = "https://www.drupal.org/files/issues/strict-warning-2149287-1.patch"
projects[views_rss_media][patch][] = "https://www.drupal.org/files/issues/views_rss_media-2550589-1.patch"
