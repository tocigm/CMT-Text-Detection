/**
 * Created by kidio on 2016. 10. 27..
 */
'use-strict';

angular
    .module('myApp')
    .factory('Item', function () {
        var self = this;

        self.init  = function(){
            return self = {
                hasPhone: false,
                cracked: '',
                hasCracked: true,
                crack_accuracy: 0,
                CMT: ''
            };
        }

        self.set = function(object){
            return self = {
                hasPhone:object.hasPhone,
                cracked: object.cracked,
                hasCracked: object.hasCracked,
                crack_accuracy: object.crack_accuracy,
                CMT: object.CMT
            }
        }

        return self
    })