import plissken

print '##############################'
print 'plissken.escape_html'

print '&: ',plissken.escape_html(u'&')
print '>: ',plissken.escape_html(u'>',False)
print '<: ',plissken.escape_html(u'<')
print '": ',plissken.escape_html(u'"')
print '\': ',plissken.escape_html(u'\'')
print '/: ',plissken.escape_html(u'/')

print '##############################'
print 'plissken.unescape_html'

print '&amp;:  ',plissken.unescape_html(u'&amp;')
print '&gt;:   ',plissken.unescape_html(u'&gt;')
print '&lt;:   ',plissken.unescape_html(u'&lt;')
print '&quot;: ',plissken.unescape_html(u'&quot;')
print '&#39;:  ',plissken.unescape_html(u'&#39;')
print '&#47;:  ',plissken.unescape_html(u'&#47;')

print '##############################'
print 'plissken.escape_js'

print '": ',plissken.escape_js(u'"')
print '\': ',plissken.escape_js(u'\'')

print '##############################'
print 'plissken.unescape_js'

print '\\": ',plissken.unescape_js(u'\\"')
print '\\\': ',plissken.unescape_js(u'\\\'')

print '##############################'
print 'plissken.escape_uri'

print 'http://example.com/?a=\\t\\r: ',plissken.escape_uri(u'http://example.com/?a=\\t\\r')

print '##############################'
print 'plissken.unescape_uri'

print 'http://example.com?a=%09%0D: ', plissken.unescape_uri(u'http://example.com?a=%09%0D')

print '##############################'