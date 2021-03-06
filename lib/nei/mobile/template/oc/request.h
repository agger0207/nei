//
//  {{conf.prefix}}{{req.name}}Request.h
//
//  Created by {{conf.author}} on {{conf.month}}/{{conf.day}}/{{conf.year}}.
//  Copyright © {{conf.year}} NetEase. All rights reserved.
//
//  Auto build by NEI Builder

#import "{{conf.prefix}}{{conf.base}}.h"
{# pre classes #}
{%- for model in req.reqModels %}
@class {{conf.prefix}}{{model}};
{%- endfor %}

/**
 *  {{req.description}}
 */
@interface {{conf.prefix}}{{req.name}} : {{conf.prefix}}{{conf.base}}
{% for header in req.reqVarHeaders %}
/**
 *  {{header.desc}}
 */
@property (nonatomic, copy) NSString *{{header.varName}};
{% endfor -%}
{% for dt in req.reqDataTypes %}
/**
 *  {{dt.description}}
 */
@property (nonatomic, {{dt.refName}}) {{dt.typeName}} {% if !dt.noStar -%}*{%- endif -%}{{dt.name}};
{% endfor %}
@end