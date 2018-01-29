getPV();
function getPV(){
    var url="https://cloud.bmob.cn/3aeb0ba8531e0e51/TEST";
    
    $.ajax({
        url:url,
        type:"GET",
        contentType:"application/json; charset=utf-8",
        dataType:'jsonp',
        data:'',
        jsonp:'callback',
        success:function(data){
            alert("Recieved "+data);
            document.getElementById("test").innerHTML=data;
        }
    });
}