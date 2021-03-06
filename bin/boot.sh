# ------------------------------------------------------------------------------------------------
# Copyright 2013 Jordon Bedwell.
# Apache License.
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file
# except  in compliance with the License. You may obtain a copy of the License at:
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software distributed under the
# License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
# either express or implied. See the License for the specific language governing permissions
# and  limitations under the License.
# ------------------------------------------------------------------------------------------------

export APP_ROOT=$HOME

export WEBTOBDIR=$APP_ROOT/webtob

PATH="${WEBTOBDIR}/bin:${PATH}"
export PATH

export LD_LIBRARY_PATH=$WEBTOBDIR/lib:${LD_LIBRARY_PATH}

echo "suna"

conf_file=$APP_ROOT/webtob/config/http.m
if [ -f $APP_ROOT/public/http.m ]
then
  conf_file=$APP_ROOT/public/http.m
fi

#mv $conf_file $APP_ROOT/webtob/config/http.m
#erb $APP_ROOT/nginx/conf/orig.conf > $APP_ROOT/nginx/conf/nginx.conf

# ------------------------------------------------------------------------------------------------

#exec $APP_ROOT/nginx/sbin/nginx -p $APP_ROOT/nginx -c $APP_ROOT/nginx/conf/nginx.conf

#(tail -f -n 0 $APP_ROOT/webtob/log/*.log* &)

#$APP_ROOT/webtob/bin/wsboot
#(tail -f -n 0 $APP_ROOT/webtob/log/*.log* &)
$APP_ROOT/webtob/bin/wscfl -i $APP_ROOT/webtob/config/http.m 
sleep 5

#(tail -f -n 0 $APP_ROOT/webtob/log/system.log* &)
exec $APP_ROOT/webtob/bin/wsboot -a
echo "suna"
# ------------------------------------------------------------------------------------------------
