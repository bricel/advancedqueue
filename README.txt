DESCRIPTION
==============
Advanced Queue is an extended queuing module fully backward compatible
with and a drop-in replacement of DrupalQueue.

Supports:

* A Drush-based execution engine for queued job, supporting executing
  multiple queues at the same time and timeouts
* A "poor-man's" processing via cron.
* Human readable, translatable names for queued items
* Tags for queued items
* Status of queued items (new, being processed, succeeded, failed), and
  result payload
* Views integration

In order to use Drush based execution engine your module must provide
hook_advanced_queue_info() in which a processing callback (worker) must be
declared. This callback will receive the item being processed and process
it.
Enable the "Advanced-queue example" module to see it in action.

Note that by default the "poor-man's" processing via cron is enabled, as it
allows site builders to start with the non-scalable and later on, more advanced
users can disable that option via admin/config/system/cron.

To use all the field and filters in the default views, Date Views (date_views)
module should be enabled.

DRUSH WORKERS
=============
It is possible to execute the Drush command that will loop and "listen" to
the queue, and process items once they are added. It is considered a best
practice to execute the Drush command with a timeout of 15 minutes, and
use supervisord to restart it once it dies. This will help making sure
there are no serious memory leaks. For example:

  drush advancedqueue --all --timeout=900

SUPERVISORD
===========
1) Install supervisord

For Ubuntu:

  sudo apt-get install supervisor

For other platforms and distributions:

  See the docs http://supervisord.org/installing.html

2) Configure supervisord to run the Drush worker

Edit your /etc/supervisor/supervisord.conf or create a new
/etc/supervisor/conf.d/advancedqueue.conf:

  [program:advancedqueue]
  command=/path/to/drush advancedqueue-process-queue --all --timeout=900 -r /path/to/drupal-install/ -l https://url.ofyour.site
  autorestart=true

For more configuration options see the supervisord documentation:

  http://supervisord.org/configuration.html

3) Start supervisord

  sudo service supervisor start

Check the status of your supervised advancedqueue process:

  sudo supervisorctl status

View supervisord logs:

  tail -f /var/log/supervisor/supervisord.log

SPONSORS & MAINTAINERS
=======================
* Sponsored by Publicis Modem
* Developed and sponsored by Commerce Guys http://commerceguys.com/
* Developed by Gizra http://www.gizra.com/

