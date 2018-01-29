
getPV();
function getPV(){
    var url="https://cloud.bmob.cn/3aeb0ba8531e0e51/getPV";
    
    $.ajax({
        url:url,
        type:"GET",
        contentType:"application/json; charset=utf-8",
        dataType:'jsonp',
        jsonp:'callback',
        success:function(data){
            var str = "你是本网站第"+data.allday+"位访客，今日第"+data.today+"位！";
            if(data.today=="1") str+="\n大吉大利，晚上吃鸡！";
            alert(str);
        }
    });
}